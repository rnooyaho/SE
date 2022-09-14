#pragma once

#include <iostream>
#include "UI.h"

//3.1 판매의류등록
void AddProductUI::startInterface(ifstream& fin, ofstream& fout)
{
	fout << "3.1. 판매 의류 등록" << endl;
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
	product->createProduct(ID, productname, companyname, productcost, quantityleft);//판매할 product 생성
	
	sellerproduct.addProduct(product);//상품 컬렉션에 추가
}

void SearchProductForSaleUI::startInterface(ifstream& fin, ofstream& fout)
{
	fout << "3.2. 등록 상품 조회" << endl;
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
