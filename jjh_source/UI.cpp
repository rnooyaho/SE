#pragma once

#include <iostream>
#include "UI.h"

//3.1 �Ǹ��Ƿ����
void AddProductUI::startInterface(ifstream& fin, ofstream& fout)
{
	fout << "3.1. �Ǹ� �Ƿ� ���" << endl;
}

void AddProductUI::enterProductInformation(ifstream& fin, ofstream& fout, AddProduct* addproduct)
{
	string productName;
	string companyName;
	int productCost;
	int quantityLeft;
	fin >> productName >> companyName >> productCost >> quantityLeft;
	addproduct->addNewProduct(productName, companyName, productCost, quantityLeft);
	fout << "> " << productName << " " << companyName << " " << productCost << " " << quantityLeft << endl;
}

AddProduct::AddProduct()
{

}

AddProduct::AddProduct(ProductCollection& sellerproduct, Client* curclient, ifstream& fin, ofstream& fout)
{
	this->loginClient = curclient;
	this->sellerproduct = sellerproduct;
	pAddProductUI = new AddProductUI;
	pAddProductUI->startInterface(fin, fout);
}

void AddProduct::addNewProduct(string productname, string companyname, int productcost, int quantityleft)
{
	Product* product = new Product;
	string ID = loginClient->getClientID();
	product->createProduct(ID, productname, companyname, productcost, quantityleft);//�Ǹ��� product ����
	
	sellerproduct.addProduct(product);//��ǰ �÷��ǿ� �߰�
}

void SearchProductForSaleUI::startInterface(ifstream& fin, ofstream& fout)
{
	fout << "3.2. ��� ��ǰ ��ȸ" << endl;
}

void SearchProductForSaleUI::selectProductForSale(SearchProductForSale* searchproductforsale)
{
	searchproductforsale->showProductForSale(searchproductforsale);
}

SearchProductForSale::SearchProductForSale()
{

}

SearchProductForSale::SearchProductForSale(ProductCollection& sellerproduct, Client* curclient, ifstream& fin, ofstream& fout)
{
	this->loginClient = curclient;
	this->sellerproduct = sellerproduct;
	pSearchProductForSaleUI = new SearchProductForSaleUI;
	pSearchProductForSaleUI->startInterface(fin, fout);
}

void SearchProductForSale::showProductForSale(SearchProductForSale* searchproductforsale)
{
	ProductCollection* list = new ProductCollection;
	list->getProduct()
		
}
