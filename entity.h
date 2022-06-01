#pragma once
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
	string socialSecurityNumber;
	string clientID;
	string clientPassword;
	int log_status;

	ProductCollection purchasedProductList; //�����ڿ��� �߰�
public:
	void createClient(string& name, string& SSN, string& ID, string& password);
	string getClientID();         //� ���� �������� ���� ��� ���� ��ȯ�ϵ��� ��������ϴ�.
	string getClientSSN();
	string getClientName();
	string getClientPW();
	bool getlog_status();
	void set_log(int log_status); // �α��λ��¸� �ٲٴ� �Լ�
	void deleteClient(); //��� �� �Ǹŷ� ����

	void addPurchaseInformation(Product* product); //�����ڿ��� �߰�
	ProductCollection getPurchasedProductList();   //�����ڿ��� �߰�
};

class ClientCollection {
private:
	vector<Client*> clients; 
public:
	int findClientIndex(string ClientName); // �̸��� ���� ���̵� �ε��� ã�� // 1.2������ ���� ���
	Client* Login(string ID, string PW);  //�α��� �� ���̵��� �α��λ��°� ������ ���� ȣ�� // 2.1�α��ο���!
	void addClient(Client* client);  // 1.1ȸ������
	void deleteClient(Client* client); // 1.2 ȸ��Ż��
	void printClient(); //���߿� ������ �Լ�. �� ȸ������ �����߿� Ȯ���Ϸ��� �־����ϴ�.
	Client* LoginID(); //�α��εǾ��ִ� ��ü ��ȯ

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


