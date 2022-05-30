#pragma once
#include <iostream>
#include "entity.h"

//������ Ŭ���� ����Լ� ����
void Purchaser::addPurchaseInformation(Product* product) //���� ��ǰ ����Ʈ �߰�
{
	purchasedProductList.addProduct(product);
}
ProductCollection Purchaser::getPurchasedProductList()
{
	return purchasedProductList;
}


//Product Ŭ���� ����Լ� ����
string Product::getProductName()
{
	return productName;
}
void Product::getProductDetails(string& ID, string& name, string& companyName, int& productCost, int& left)
{
	ID = sellerID;
	name = productName;
	companyName = productCompanyName;
	productCost = this->cost;
	left = this->quantityLeft;
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


//collection class ��� �Լ� ����
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