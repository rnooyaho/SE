#pragma once
#pragma once
#include <fstream>
#include <string>
#include <vector>
#include "entity.h"
using namespace std;

//���� ����
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

// 1.1 ȸ������ UI
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

//1.2 ȸ��Ż��
class DeleteClientAccountUI {

public:
	void interface(ofstream& fout);
	void deleteClientAccount(ClientCollection &client, ofstream& fout);

};

//ui������ ������ ���� client���� ����
class DeleteClientAccount {
	DeleteClientAccountUI* DCA_UI;
public:
	void deleteClient(ifstream& fin, ClientCollection& clients, ofstream& fout);
};
//////


//2.1 �α��� (���̾�׷��� 1.getclient�� �ƴ� ���� �������� client���� �����ϵ��� �������)
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

//2.2�α׾ƿ� (�α��λ��� �Ǻ��� �α��� �����Ͻ� �α׾ƿ�) 

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

//boundary class ����
class SearchUI {
	string productName;
	Product* selected; //�߰��� �κ�
public:
	void startInterface(ifstream& fin, ofstream& fout);
	void enterProductName(Search* search, ProductCollection products, ofstream& fout); //searchProductName���� �ٲٴ� �� ��������..
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


//control class ����
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