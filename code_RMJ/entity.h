#pragma once
#include <fstream>
#include <string>
#include <vector>
using namespace std;
//���� ����
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
	Client() { // 4���� �� ���ư����� ������ ���� ������. 
		clientName = "part";
		socialSecurityNumber = 123456;
		clientID = "obs";
		clientPassword = "pw2d";

	}
	*/
	void createCleint() {};
	string getClient() { return clientID; };
	void deleteClient() {};
	string getClientID() { return clientID; }; //�߰��ߴµ� getClient�� ��ġ�� �ʿ�x
};



class Product {
private:
	string sellerID; //�߰�
	string productName;
	string productCompanyName;
	int cost;
	int quantityLeft;
	int quantitysold;
	float averageScore;

public:
	/*
	Product() { //��������� ���� ������. push ���� �����. 
		sellerID = "mbc";
		productName = "hat";
		productCompanyName = "chulsoo";
		cost = 2000;
		quantityLeft = 2;
		quantitysold = 0;
		averageScore = 0.0; //���Ÿ����� �ʱⰪ�� 0. �̰͸� ���ܵα�. 
	}
	*/
	void getProductDetails(string& ID, string& name, string& companyName, int& productCost, int& left);
	string getProductName();//�ʿ��ؼ� �߰���
	string getName(); //���� �߰��� �Լ�. Search���� �ʿ���.
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