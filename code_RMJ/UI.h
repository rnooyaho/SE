#pragma once
#include <fstream>
#include <string>
#include <vector>
#include "entity.h"
using namespace std;

//전방 선언
class SearchUI;
class ShowShoppingListUI;
class SatisfactionScoreUI;
class PurchaseUI;
class Search;
class ShowShopping;
class SatisfactionScore;
class Purchase;

//boundary class 선언
class SearchUI {
	string productName;
	Product* selected; //추가한 부분
public:
	void startInterface(ifstream& fin, ofstream& fout);
	void enterProductName(Search* search, ProductCollection products, ofstream& fout); //searchProductName으로 바꾸는 게 나을수도..
	Product* selectPurchase();
};
class ShowShoppingListUI {
public:
	void startInterface(ProductCollection list, ofstream& fout);
	//void selectProductSatisfaction();
};
class SatisfactionScoreUI {
public:
	void startInterface(ifstream& fin, string& productName, int& score, ofstream& fout);
	void printScore(string sellerID, string productName, int score, ofstream& fout);
	//void enterScore();
};
class PurchaseUI {
	Purchase* purchase;
public:
	void startInterface(Product* product, Client* actor, ofstream& fout, Purchase* purchase);
	void purchaseProduct();
};

//control class 선언
class Search {
	SearchUI* searchUI;
public:
	Product* run(ifstream& fin, ProductCollection products, Product*& selected, ofstream& fout);
	Product* searchProduct(string productName, ProductCollection products);
};
class Purchase {
	Product* product;
	PurchaseUI* purchaseUI;
	Client* actor;
public:
	Client* run(Product* product, Client* actor, ofstream& fout);
	void purchaseProduct();
};
class ShowShopping {
public:
	void run(Client* actor, ofstream& fout);
};

class SatisfactionScore {
public:

	void run(ifstream& fin, Client* actor, ofstream& fout);
	//void enterScore();
};



