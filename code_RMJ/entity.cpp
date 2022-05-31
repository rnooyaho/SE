#pragma once
#include <iostream>
#include "entity.h"

//Client Ŭ���� ����Լ�(������ �κ�) ����
void Client::addPurchaseInformation(Product* product) //���� ��ǰ ����Ʈ �߰�
{
	purchasedProductList.addProduct(product);
}
ProductCollection Client::getPurchasedProductList()
{
	return purchasedProductList;
}


//Product Ŭ���� ����Լ� ����
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
void Product::stockCorrection() //��� �� �Ǹŷ� ����
{
	quantityLeft--; //��� - 1
	quantitysold++; //�Ǹż��� + 1
}
void Product::setScore(int score)//��� ���Ÿ����� ���.
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


//product collection class ��� �Լ� ����
Product* ProductCollection::findProduct(string productName)//��ǰ ���� �˻��� �̿�
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
void ProductCollection::addProduct(Product* product) //���� ���� �߰��� �̿�
{
	products.push_back(product);
}
int ProductCollection::getSize() //��ǰ ���� ����
{
	return products.size();
}
Product* ProductCollection::getProduct(int i) //����Ʈ ��ȸ��
{
	return products[i];
}