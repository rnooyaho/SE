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
	string getClientID(); //�߰��ߴµ� getClient�� ��ġ�� �ʿ�x
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
	string sellerID; //�߰�
	string productName;
	string productCompanyName;
	int cost;
	int quantityLeft;
	int quantitysold;
	float averageScore;

public:
	void getProductDetails(ofstream& fout);
	string getProductName();//�ʿ��ؼ� �߰���
	string getName(); //���� �߰��� �Լ�. Search���� �ʿ���.
	void setScore(int score);
	void stockCorrection();
	void createProduct();
	void getProductCostAndScore();

};


