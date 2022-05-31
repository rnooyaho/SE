#pragma once
#include <iostream>
#include "entity.h"

//Client 클래스 멤버함수(구매자 부분) 구현
void Client::addPurchaseInformation(Product* product) //구매 상품 리스트 추가
{
	purchasedProductList.addProduct(product);
}
ProductCollection Client::getPurchasedProductList()
{
	return purchasedProductList;
}


//Product 클래스 멤버함수 구현
string Product::getProductName()
{
	return productName;
}
void Product::getProductDetails(string& ID, string& name, string& companyName, int& productCost, int& left, float& score)
{
	ID = sellerID;
	name = productName;
	companyName = productCompanyName;
	productCost = this->cost;
	left = this->quantityLeft;
	score = this->averageScore;
}
void Product::stockCorrection() //재고 및 판매량 수정
{
	quantityLeft--; //재고 - 1
	quantitysold++; //판매수량 + 1
}
void Product::setScore(int score)//평균 구매만족도 계산.
{
	float totalScore = (averageScore * (quantitysold - 1)) + float(score);
	averageScore = (totalScore / quantitysold);
}
string Product::getName()
{
	return this->productName;
}
string Product::getSellerID()
{
	return this->sellerID;
}


//product collection class 멤버 함수 구현
Product* ProductCollection::findProduct(string productName)//상품 정보 검색에 이용
{
	int i = 0;
	for (i = 0; i < products.size(); ++i)
	{
		if (products[i]->getName() == productName)
		{
			break;
		}

	}
	return products[i];
}
void ProductCollection::addProduct(Product* product) //구매 정보 추가에 이용
{
	products.push_back(product);
}
int ProductCollection::getSize() //상품 개수 리턴
{
	return products.size();
}
Product* ProductCollection::getProduct(int i) //리스트 순회용
{
	return products[i];
}