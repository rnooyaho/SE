#pragma once
#include <fstream>
#include <string>
#include <vector>
using namespace std;
//전방 선언
class Client;
class Product;
class ProductCollection;
class Purchaser; 

class Client {
private:
	string clientName;
	int socialSecurityNumber;
	string clientID;
	string clientPassword;

public:
	/*
	Client() { // 4번대 잘 돌아가는지 보려고 만든 생성자. 
		clientName = "part";
		socialSecurityNumber = 123456;
		clientID = "obs";
		clientPassword = "pw2d";

	}
	*/
	void createCleint() {};
	string getClient() { return clientID; };
	void deleteClient() {};
	string getClientID() { return clientID; }; //추가했는데 getClient랑 겹치면 필요x
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
	/*
	Product() { //실험용으로 만든 생성자. push 전에 지우기. 
		sellerID = "mbc";
		productName = "hat";
		productCompanyName = "chulsoo";
		cost = 2000;
		quantityLeft = 2;
		quantitysold = 0;
		averageScore = 0.0; //구매만족도 초기값은 0. 이것만 남겨두기. 
	}
	*/
	void getProductDetails(string& ID, string& name, string& companyName, int& productCost, int& left);
	string getProductName();//필요해서 추가함
	string getName(); //새로 추가한 함수. Search에서 필요함.
	string getSellerID();
	void setScore(int score);
	void stockCorrection();
	void createProduct() {}; //
	void getProductCostAndScore() {};//

};


class ProductCollection {
private:
	vector<Product*> products;
public:
	Product* findProduct(string productName);
	void addProduct(Product* product);
	int getSize();
	Product* getProduct(int i);
};

class Purchaser :public Client {
private:
	ProductCollection purchasedProductList;
public:
	void addPurchaseInformation(Product* product);
	ProductCollection getPurchasedProductList();
};