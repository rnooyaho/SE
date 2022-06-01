#pragma once
#pragma once
#include <fstream>
#include <string>
#include <vector>
#include "entity.h"
using namespace std;

//전방 선언
class CreateClientAccountUI;
class CreateClientAccount;
class DeleteClientAccountUI;
class DeleteClientAccount;
class LoginUI;
class Login;
class LogoutUI;
class Logout;



class SearchUI;
class ShowShoppingListUI;
class SatisfactionScoreUI;
class PurchaseUI;
class Search;
class ShowShopping;
class SatisfactionScore;
class Purchase;

// 1.1 회원가입 UI
class CreateClientAccountUI {

public:
	void interface(ofstream& fout);
	Client* enterClientInformation(ifstream& fin, ofstream& fout);
	
};
class CreateClientAccount {
	CreateClientAccountUI* CCA_UI;
public:
	void addNewClient(ifstream& fin, ClientCollection &clients , ofstream& fout);
};

//1.2 회원탈퇴
class DeleteClientAccountUI {

public:
	void interface(ofstream& fout);
	void deleteClientAccount(ClientCollection &client, ofstream& fout);

};

//ui에서의 정보를 통해 client정보 수정
class DeleteClientAccount {
	DeleteClientAccountUI* DCA_UI;
public:
	void deleteClient(ifstream& fin, ClientCollection& clients, ofstream& fout);
};
//////


//2.1 로그인 (다이어그램을 1.getclient가 아닌 가장 마지막에 client한테 전달하도록 수정요망)
class LoginUI {
public:
	void interface(ofstream& fout);
	string *selectLogin(ifstream& fin, ofstream& fout);
};

class Login {
	LoginUI* Login_UI;
public:
	void tryLogin(ifstream& fin, ClientCollection& clients, ofstream& fout);

};

//2.2로그아웃 (로그인상태 판별후 로그인 상태일시 로그아웃) 

class LogoutUI {
public:
	void interface(ofstream& fout);
	void selectLogout(ClientCollection& clients, ofstream& fout);
};

class Logout {
	LogoutUI* Logout_UI;
public:
	void tryLogout(ClientCollection& clients, ofstream& fout);

};






/*

class Search {
	SearchUI* searchUI;
public:
	Product* run(ifstream& fin, ProductCollection products, Product*& selected, ofstream& fout);
	Product* searchProduct(string productName, ProductCollection products);
};

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
	void startInterface(Product* product, Purchaser* actor, ofstream& fout, Purchase* purchase);
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





*/