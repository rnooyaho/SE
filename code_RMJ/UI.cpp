#pragma once
#include <iostream>
#include "UI.h"

//4.1. ��ǰ ���� �˻� ����
void SearchUI::startInterface(ifstream& fin)
{
	string productName;
	fin >> productName;
	this->productName = productName;
}
void SearchUI::enterProductName(Search* search, ProductCollection products, ofstream& fout) //��ǰ ���� �˻� 2.
{
	this->selected = search->searchProduct(productName, products,fout);
}
Product* SearchUI::selectPurchase()
{
	return selected;
}

Product* Search::run(ifstream& fin, ProductCollection products, Product*& selected, ofstream& fout) //��ǰ ���� �˻� 0.
{
	fout << "4.1. ��ǰ ���� �˻�" << endl;

	searchUI = new SearchUI;
	searchUI->startInterface(fin); //��ǰ ���� �˻� 1.
	searchUI->enterProductName(this, products, fout); //��ǰ ���� �˻� 2.

	selected = searchUI->selectPurchase();
	return selected;
}
Product* Search::searchProduct(string productName, ProductCollection products, ofstream& fout) //��ǰ ���� �˻� 2.1.
{
	Product* product = products.findProduct(productName);
	product->getProductDetails(fout); 
	return product;
}


//4.2. ��ǰ ���� ����
void PurchaseUI::startInterface(Purchase* purchase) //4.1.
{
	this->purchase = purchase;
	purchaseProduct();
}
void PurchaseUI::purchaseProduct() //4.1.1.
{
	purchase->purchaseProduct();
}
Purchaser* Purchase::run(Product* product, Purchaser* actor, ofstream& fout)
{
	fout << "4.2. ��ǰ ����\n";
	this->product = product;
	this->actor = actor;
	purchaseUI = new PurchaseUI;
	purchaseUI->startInterface(this); //4.1.
	
	fout << "> " << product->getSellerID() << " " << product->getProductName() << endl; //�Ǹ��� ���̵�� ��ǰ��.

	return actor;
}
void Purchase::purchaseProduct()
{
	actor->addPurchaseInformation(this->product);//4.1.1.1.1.�����ڿ��� ���� ���� �߰�
	product->stockCorrection(); //4.1.1.1.2.��� ����
}

//4.3. ��ǰ ���� ���� ��ȸ ����
void ShowShopping::run(Purchaser* actor, ofstream& fout)
{
	ProductCollection list;
	fout << "4.3. ��ǰ ���� ���� ��ȸ" << endl;
	list = actor->getPurchasedProductList(); //1.

	if (list.getSize() == 0)
	{
		cout << "���� ���� ����" << endl;
		return;
	}

	for (int i = 0; i < list.getSize(); ++i)
	{
		list.getProduct(i)->getProductDetails(fout); //2.
	}
	ShowShoppingListUI UI;
	UI.startInterface(fout);

}
void ShowShoppingListUI::startInterface(ofstream& fout)
{
	fout << "\n";
}

//4.4. ���Ÿ����� ����
void SatisfactionScoreUI::startInterface(ifstream& fin, string& productName, int& score)
{
	//��ǰ��� ���� ������ �Է�
	fin >> productName >> score;
}
void SatisfactionScore::run(ifstream& fin, Purchaser* actor, ofstream& fout)
{
	string productName;
	int score;
	SatisfactionScoreUI* UI = new SatisfactionScoreUI;
	UI->startInterface(fin, productName, score);

	//���Ͽ� ����
	fout << "4.4. ��ǰ ���� ������ ��\n";
	ProductCollection list;
	list = actor->getPurchasedProductList();
	Product* product;
	product = list.findProduct(productName);
	product->setScore(score);
	fout << "> " << product->getSellerID() << " " << productName << " " << score << "\n";
}