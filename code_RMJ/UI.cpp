#pragma once
#include <iostream>
#include "UI.h"

//4.1. 상품 정보 검색 구현
void SearchUI::startInterface(ifstream& fin, ofstream& fout)
{
	fout << "4.1. 상품 정보 검색" << endl;

	string productName;
	fin >> productName;
	this->productName = productName;
}
void SearchUI::enterProductName(Search* search, ProductCollection products, ofstream& fout) //상품 정보 검색 2.
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

Product* Search::run(ifstream& fin, ProductCollection products, Product*& selected, ofstream& fout) //상품 정보 검색 0.
{
	
	searchUI = new SearchUI;
	searchUI->startInterface(fin, fout); //상품명 입력 받음
	searchUI->enterProductName(this, products, fout); //입력받은 상품 정보 출력 

	selected = searchUI->selectPurchase(); //구매 버튼 반환.
	return selected;
}
Product* Search::searchProduct(string productName, ProductCollection products) //상품 정보 검색 2.1.
{
	Product* product = products.findProduct(productName);
	//product->getProductDetails(); 
	return product;
}


/*
4.2. 상품 구매 구현
출력 예시
4.2. 상품 구매
> mbc hat
*/
void PurchaseUI::startInterface(Product* product, Purchaser* actor, ofstream& fout, Purchase* purchase) //4.1.
{
	this->purchase = purchase;
	purchaseProduct();
	fout << "> " << product->getSellerID() << " " << product->getProductName() << endl; //판매자 아이디와 상품명.
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
	purchaseUI->startInterface(product, actor, fout, this); //4.1.
	
	return actor;
}
void Purchase::purchaseProduct()
{
	actor->addPurchaseInformation(this->product);//4.1.1.1.1.구매자에게 구매 정보 추가
	product->stockCorrection(); //4.1.1.1.2.재고 수정
}

/*
4.3. 상품 구매 내역 조회 구현
출력 예시
4.3. 상품 구매 내역 조회
> mbc hat chulsoo 2000 1
*/
void ShowShopping::run(Purchaser* actor, ofstream& fout)
{
	ProductCollection list;
	ShowShoppingListUI UI;	
	list = actor->getPurchasedProductList(); //구매 내역 불러오기.

	UI.startInterface(list, fout); //구매내역 interface로 전달. 
}
void ShowShoppingListUI::startInterface(ProductCollection list, ofstream& fout)
{
	fout << "4.3. 상품 구매 내역 조회" << endl;
	if (list.getSize() == 0)
	{
		cout << "구매 내역 없음" << endl;
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
4.4. 구매만족도 구현
출력 예시
4.4. 상품 구매 만족도 평가
> mbc hat 3
*/
void SatisfactionScoreUI::startInterface(ifstream& fin, string& productName, int& score, ofstream& fout)
{
	fout << "4.4. 상품 구매 만족도 평가\n";
	fin >> productName >> score; //상품명과 구매 만족도 입력 받음
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
	UI->startInterface(fin, productName, score, fout); //UI에서 제품명과 만족도 입력. 

	ProductCollection list;
	list = actor->getPurchasedProductList(); //구매 리스트 불러오기.
	Product* product;
	product = list.findProduct(productName); //제품명으로 제품 찾기.
	product->setScore(score); //평균 만족도 갱신

	UI->printScore(product->getSellerID(), productName, score, fout); //UI에서 판매자 ID, 제품명, 평균 만족도 출력.

}