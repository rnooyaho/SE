#pragma once
#include <fstream>
#include <string>
#include <vector>
#include "entity.h"
using namespace std;
//boundary class ����
class SearchUI{
	string productName;
	Product* selected; //�߰��� �κ�
public:
	void startInterface(ifstream& fin);
	void enterProductName(Search* search, vector<Product*> products, ofstream& fout); //searchProductName���� �ٲٴ� �� ��������..
	Product* selectPurchase();
};
class ShowShoppingListUI {
public:
	void startInterface(ofstream& fout);
	//void selectProductSatisfaction();
};
class SatisfactionScoreUI {
public:
	void startInterface(ifstream& fin, string& productName, int& score);
	//void enterScore();
};
class PurchaseUI {
	Purchase* purchase;
public:
	void startInterface(Purchase* purchase);
	void purchaseProduct();
};

//control class ����
class Search {
	SearchUI* searchUI;
public:
	Search(ifstream& fin, vector<Product*> products, Product* selected, ofstream& fout);
	Product* searchProduct(string productName, vector<Product*> products, ofstream& fout);
};
class ShowShopping {
public:
	ShowShopping(Purchaser* actor, ofstream& fout);
};
class SatisfactionScore {
public:
	SatisfactionScore(ifstream& fin, Purchaser* actor, ofstream& fout);
	//void enterScore();
};
class Purchase {
	Product* product;
	PurchaseUI* purchaseUI;
	Purchaser* actor;
public:
	Purchase(Product* product, Purchaser* actor, ofstream& fout);
	void purchaseProduct();
};



