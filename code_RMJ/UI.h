#pragma once
#include <fstream>
#include <string>
#include <vector>
#include "entity.h"
using namespace std;

//���� ����
class SearchUI;
class ShowShoppingListUI;
class SatisfactionScoreUI;
class PurchaseUI;
class Search;
class ShowShopping;
class SatisfactionScore;
class Purchase;

//boundary class ����
class SearchUI{
	string productName;
	Product* selected; //�߰��� �κ�
public:
	void startInterface(ifstream& fin);
	void enterProductName(Search* search, ProductCollection products, ofstream& fout); //searchProductName���� �ٲٴ� �� ��������..
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
	Product* run(ifstream& fin, ProductCollection products, Product*& selected, ofstream& fout);
	Product* searchProduct(string productName, ProductCollection products, ofstream& fout);
};
class Purchase {
	Product* product;
	PurchaseUI* purchaseUI;
	Purchaser* actor;
public:
	Purchaser* run(Product* product, Purchaser* actor, ofstream& fout);
	void purchaseProduct();
};
class ShowShopping {
public:
	void run(Purchaser* actor, ofstream& fout);
};

class SatisfactionScore {
public:

	void run(ifstream& fin, Purchaser* actor, ofstream& fout);
	//void enterScore();
};





