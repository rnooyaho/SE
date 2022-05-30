#pragma once
#include <iostream>
#include "UI.h"

//4.1. ��ǰ ���� �˻� ����
void SearchUI::startInterface(ifstream& fin, ofstream& fout)
{
	fout << "4.1. ��ǰ ���� �˻�" << endl;

	string productName;
	fin >> productName;
	this->productName = productName;
}
void SearchUI::enterProductName(Search* search, ProductCollection products, ofstream& fout) //��ǰ ���� �˻� 2.
{
	string sellerID;
	string name;
	string companyName;
	int productCost;
	int quantityLeft;

	this->selected = search->searchProduct(this->productName, products);
	selected->getProductDetails(sellerID, name, companyName, productCost, quantityLeft);
	fout << "> " << sellerID << " " << productName << " " << companyName << " " << productCost << " " << quantityLeft << "\n";
}
Product* SearchUI::selectPurchase()
{
	return selected;
}

Product* Search::run(ifstream& fin, ProductCollection products, Product*& selected, ofstream& fout) //��ǰ ���� �˻� 0.
{
	
	searchUI = new SearchUI;
	searchUI->startInterface(fin, fout); //��ǰ�� �Է� ����
	searchUI->enterProductName(this, products, fout); //�Է¹��� ��ǰ ���� ��� 

	selected = searchUI->selectPurchase(); //���� ��ư ��ȯ.
	return selected;
}
Product* Search::searchProduct(string productName, ProductCollection products) //��ǰ ���� �˻� 2.1.
{
	Product* product = products.findProduct(productName);
	//product->getProductDetails(); 
	return product;
}


/*
4.2. ��ǰ ���� ����
��� ����
4.2. ��ǰ ����
> mbc hat
*/
void PurchaseUI::startInterface(Product* product, Purchaser* actor, ofstream& fout, Purchase* purchase) //4.1.
{
	this->purchase = purchase;
	purchaseProduct();
	fout << "> " << product->getSellerID() << " " << product->getProductName() << endl; //�Ǹ��� ���̵�� ��ǰ��.
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
	purchaseUI->startInterface(product, actor, fout, this); //4.1.
	
	return actor;
}
void Purchase::purchaseProduct()
{
	actor->addPurchaseInformation(this->product);//4.1.1.1.1.�����ڿ��� ���� ���� �߰�
	product->stockCorrection(); //4.1.1.1.2.��� ����
}

/*
4.3. ��ǰ ���� ���� ��ȸ ����
��� ����
4.3. ��ǰ ���� ���� ��ȸ
> mbc hat chulsoo 2000 1
*/
void ShowShopping::run(Purchaser* actor, ofstream& fout)
{
	ProductCollection list;
	ShowShoppingListUI UI;	
	list = actor->getPurchasedProductList(); //���� ���� �ҷ�����.

	UI.startInterface(list, fout); //���ų��� interface�� ����. 
}
void ShowShoppingListUI::startInterface(ProductCollection list, ofstream& fout)
{
	fout << "4.3. ��ǰ ���� ���� ��ȸ" << endl;
	if (list.getSize() == 0)
	{
		cout << "���� ���� ����" << endl;
		return;
	}
	string sellerID;
	string productName;
	string companyName;
	int productCost;
	int quantityLeft;

	for (int i = 0; i < list.getSize(); ++i)
	{
		list.getProduct(i)->getProductDetails(sellerID, productName, companyName, productCost, quantityLeft);
		fout << "> " << sellerID << " " << productName << " " << companyName << " " << productCost << " " << quantityLeft << "\n";
	}
}

/*
4.4. ���Ÿ����� ����
��� ����
4.4. ��ǰ ���� ������ ��
> mbc hat 3
*/
void SatisfactionScoreUI::startInterface(ifstream& fin, string& productName, int& score, ofstream& fout)
{
	fout << "4.4. ��ǰ ���� ������ ��\n";
	fin >> productName >> score; //��ǰ��� ���� ������ �Է� ����
}
void SatisfactionScoreUI::printScore(string sellerID, string productName,int score, ofstream& fout)
{
	fout << "> " << sellerID << " " << productName << " " << score << "\n";
}
void SatisfactionScore::run(ifstream& fin, Purchaser* actor, ofstream& fout)
{
	string productName;
	int score;
	SatisfactionScoreUI* UI = new SatisfactionScoreUI;
	UI->startInterface(fin, productName, score, fout); //UI���� ��ǰ��� ������ �Է�. 

	ProductCollection list;
	list = actor->getPurchasedProductList(); //���� ����Ʈ �ҷ�����.
	Product* product;
	product = list.findProduct(productName); //��ǰ������ ��ǰ ã��.
	product->setScore(score); //��� ������ ����

	UI->printScore(product->getSellerID(), productName, score, fout); //UI���� �Ǹ��� ID, ��ǰ��, ��� ������ ���.

}