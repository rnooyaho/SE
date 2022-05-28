#pragma once
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class Client {
private:
	string clientName;
	int socialSecurityNumber;
	string clientID;
	string clientPassword;

public:
	void createCleint();
	void getClient();
	void deleteClient();
	string getClientID(); //추가했는데 getClient랑 겹치면 필요x
};

class Purchaser :public Client {
private:
	vector<Product*> purchasedProductList;
public:
	void addPurchaseInformation(Product* product);
	vector<Product*> getPurchasedProductList();
};

class Product {
private:
	string sellerID; //추가
	string productName;
	string productCompanyName;
	int cost;
	int quantityLeft;
	int quantitysold;
	float averageScore;

public:
	void getProductDetails(ofstream& fout);
	string getProductName();//필요해서 추가함
	string getName(); //새로 추가한 함수. Search에서 필요함.
	void setScore(int score);
	void stockCorrection();
	void createProduct();
	void getProductCostAndScore();

};


