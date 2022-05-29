#pragma once
#include <iostream>
#include "UI.h"

//4.1. 상품 정보 검색 구현
void SearchUI::startInterface(ifstream& fin)
{
	string productName;
	fin >> productName;
	this->productName = productName;
}
void SearchUI::enterProductName(Search* search, ProductCollection products, ofstream& fout) //상품 정보 검색 2.
{
	this->selected = search->searchProduct(productName, products,fout);
}
Product* SearchUI::selectPurchase()
{
	return selected;
}

Product* Search::run(ifstream& fin, ProductCollection products, Product*& selected, ofstream& fout) //상품 정보 검색 0.
{
	fout << "4.1. 상품 정보 검색" << endl;

	searchUI = new SearchUI;
	searchUI->startInterface(fin); //상품 정보 검색 1.
	searchUI->enterProductName(this, products, fout); //상품 정보 검색 2.

	selected = searchUI->selectPurchase();
	return selected;
}
Product* Search::searchProduct(string productName, ProductCollection products, ofstream& fout) //상품 정보 검색 2.1.
{
	Product* product = products.findProduct(productName);
	product->getProductDetails(fout); 
	return product;
}


//4.2. 상품 구매 구현
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
	fout << "4.2. 상품 구매\n";
	this->product = product;
	this->actor = actor;
	purchaseUI = new PurchaseUI;
	purchaseUI->startInterface(this); //4.1.
	
	fout << "> " << product->getSellerID() << " " << product->getProductName() << endl; //판매자 아이디와 상품명.

	return actor;
}
void Purchase::purchaseProduct()
{
	actor->addPurchaseInformation(this->product);//4.1.1.1.1.구매자에게 구매 정보 추가
	product->stockCorrection(); //4.1.1.1.2.재고 수정
}

//4.3. 상품 구매 내역 조회 구현
void ShowShopping::run(Purchaser* actor, ofstream& fout)
{
	ProductCollection list;
	fout << "4.3. 상품 구매 내역 조회" << endl;
	list = actor->getPurchasedProductList(); //1.

	if (list.getSize() == 0)
	{
		cout << "구매 내역 없음" << endl;
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

//4.4. 구매만족도 구현
void SatisfactionScoreUI::startInterface(ifstream& fin, string& productName, int& score)
{
	//상품명과 구매 만족도 입력
	fin >> productName >> score;
}
void SatisfactionScore::run(ifstream& fin, Purchaser* actor, ofstream& fout)
{
	string productName;
	int score;
	SatisfactionScoreUI* UI = new SatisfactionScoreUI;
	UI->startInterface(fin, productName, score);

	//파일에 쓰기
	fout << "4.4. 상품 구매 만족도 평가\n";
	ProductCollection list;
	list = actor->getPurchasedProductList();
	Product* product;
	product = list.findProduct(productName);
	product->setScore(score);
	fout << "> " << product->getSellerID() << " " << productName << " " << score << "\n";
}