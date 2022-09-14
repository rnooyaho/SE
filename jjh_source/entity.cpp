#pragma once
#include <iostream>
#include "entity.h"

void Product::getProductDetails(string& ID, string& name, string& companyName, int& productCost, int& left)
{
	ID = sellerID;
	name = productName;
	companyName = productCompanyName;
	productCost = this->cost;
	left = this->quantityLeft;
}

void Product::createProduct(string ID, string productname, string companyname, int productcost, int quantityleft)
{
	sellerID = ID;
	productName = productname;
	productCompanyName = companyname;
	cost = productcost;
	quantityLeft = quantityleft;
}

string Product::getSellerID()
{
	return this->sellerID;
}


//collection class 멤버 함수 구현
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
void ProductCollection::addProduct(Product* product)
{
	products.push_back(product);
}
int ProductCollection::getSize()
{
	return products.size();
}
Product* ProductCollection::getProduct(int i)
{
	return products[i];
}

string Client::getClientID()
{
	return clientID;
}