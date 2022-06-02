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

class AddProductUI;
class AddProduct;
class ProductForSaleUI;
class ProductForSale;
class ListSoldProductUI;
class ListSoldProduct;
class ShowStatisticsUI;
class ShowStatistic;

// 1.1 ȸ������ UI
class CreateClientAccountUI {

public:
	void interface(ofstream& fout);
	Client* enterClientInformation(ifstream& fin, ofstream& fout);

};
class CreateClientAccount {
	CreateClientAccountUI* CCA_UI;
public:
	void addNewClient(ifstream& fin, ClientCollection& clients, ofstream& fout);
};

//1.2 ȸ��Ż��
class DeleteClientAccountUI {

public:
	void interface(ofstream& fout);
	void deleteClientAccount(ClientCollection& client, ofstream& fout);

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
	string* selectLogin(ifstream& fin, ofstream& fout);
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

/*3.1. �Ǹ� �Ƿ� ���*/
/*Boundary*/
class AddProductUI {
public:
	void startInterface(ifstream& fin, string& productName, string& companyName, int& cost, int& quantityLeft, ofstream& fout);
	void printNewProduct(ofstream& fout, Product* product);
	void enterInformation(ifstream& fin, string& productName, string& companyName, int& cost, int& quantityLeft); //�߰��� �κ�
	//void enterProductInformation(); 
};
/*control*/
class AddProduct {
public:
	void run(ifstream& fin, Client* actor, ProductCollection& totalProduct, ofstream& fout);

	//void addNewProduct(string productName, string companyName, int cost, int quantityLeft);
};


/*3.2. �Ǹ����� �Ƿ� ��ȸ*/
/*Boundary*/
class ProductForSaleUI {
public:
	void startInterface(ofstream& fout);
	void showProductForSales(ProductCollection products, ofstream& fout);
};
/*control*/
class ProductForSale {
public:
	//void showProductForSales();

	void run(Client* actor, ofstream& fout);//���� �߰�
};

/* 3.3. �Ǹ� �Ϸ�� ��ǰ ���� ��ȸ*/
/*Boundary*/
class ListSoldProductUI {
public:
	void startInterface(ofstream& fout);
	void showSoldProductList(ProductCollection products, ofstream& fout);
};
/*control*/
class ListSoldProduct {
public:
	//void showSoldProductList();
	void run(Client* actor, ofstream& fout);
};

/*4.1. ��ǰ ���� �˻�*/
/*Boundary*/
class SearchUI {
	string productName;
	Product* selected; //�߰��� �κ�
public:
	void startInterface(ifstream& fin, ofstream& fout);
	void enterProductName(Search* search, ProductCollection products, ofstream& fout); //searchProductName���� �ٲٴ� �� ��������..
	Product* selectPurchase();
};
/*control*/
class Search {
	SearchUI* searchUI;
public:
	Product* run(ifstream& fin, ProductCollection products, Product*& selected, ofstream& fout);
	Product* searchProduct(string productName, ProductCollection products);
};

/*4.2. ��ǰ ����*/
/*Boundary*/
class PurchaseUI {
	Purchase* purchase;
public:
	void startInterface(Product* product, Client* actor, ofstream& fout, Purchase* purchase);
	void purchaseProduct();
};
/*control*/
class Purchase {
	Product* product;
	PurchaseUI* purchaseUI;
	Client* actor;
public:
	Client* run(Product* product, Client* actor, ofstream& fout);
	void purchaseProduct();
};

/*4.3. ��ǰ ���� ���� ��ȸ*/
/*Boundary*/
class ShowShoppingListUI {
public:
	void startInterface(ProductCollection list, ofstream& fout);
	//void selectProductSatisfaction();
};
/*control*/
class ShowShopping {
public:
	void run(Client* actor, ofstream& fout);
};

/*4.4. ��ǰ ���� ������ ��*/
/*Boundary*/
class SatisfactionScoreUI {
public:
	void startInterface(ifstream& fin, string& productName, int& score, ofstream& fout);
	void enterNameAndScore(ifstream& fin, string& productName, int& score); //�߰��� �κ� 
	void printScore(string sellerID, string productName, int score, ofstream& fout);
};
/*control*/
class SatisfactionScore {
public:

	void run(ifstream& fin, Client* actor, ofstream& fout);
};

/*5.1. �Ǹ� �Ϸ�� ��ǰ ���� ��ȸ*/
/*Boundary*/
class ShowStatisticsUI
{
public:
	void startInterface(ofstream& fout);
	void showStatistics(ProductCollection list, ofstream& fout);
};
/*control*/
class ShowStatistic {
public:
	//void showTotalSalesAndAverage();
	void run(Client* actor, ofstream& fout);
};




