#pragma once
#include <fstream>
#include <string>
#include <vector>
using namespace std;

class Client;
class Product;
class ProductCollection;
class Purchaser;

class Client {
private:
	string clientName;
	string socialSecurityNumber;
	string clientID;
	string clientPassword;
public:
	void createClient(string& name, string& SSN, string& ID, string& password);
	string getClientID();
};

class Product {
private:
	string sellerID;
	string productName;
	string productCompanyName;
	int cost;
	int quantityLeft;
	int quantitysold;
	float averageScore;

public:
	void getProductDetails(string& ID, string& name, string& companyName, int& productCost, int& left);
	string getProductName();
	string getName();
	string getSellerID();
	void setScore(int score);
	void stockCorrection();
	void createProduct(string ID, string productname, string companyname, int productcost, int quantityleft);
	void getProductCostAndScore();
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

class Seller : public Client {
private:
	ProductCollection soldProductList;
public:
	void getSeller();
	ProductCollection getSoldProductList();
};