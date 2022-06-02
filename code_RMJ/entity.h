#pragma once
#include <fstream>
#include <string>
#include <vector>
using namespace std;
//���� ����
class Client;
class Product;
class ProductCollection;
class ClientCollection;

//Product Ŭ���� ����
class Product {
private:
	string sellerID; 
	string productName;
	string productCompanyName;
	int cost;
	int quantityLeft;
	int quantitysold;
	int averageScore;

	Client* seller;


public:

	Product(Client* actor, string productName, string companyName, int cost, int quantityLeft); //�Ǹ� ���� ���

	void getProductDetails(string& ID, string& name, string& companyName, int& productCost, int& left, float& score);
	string getProductName();
	string getName(); 
	string getSellerID();
	void setScore(int score);
	void stockCorrection();

	int getQuantityLeft();
	int getQuantitySold();
	int getScore();
	int calculateProfit();

};

//ProductCollection Ŭ���� ����
class ProductCollection {
private:
	vector<Product*> products;
public:
	Product* findProduct(string productName);
	void addProduct(Product* product);
	int getSize();
	Product* getProduct(int i);

	void sortList();
};

//Client Ŭ���� ����
class Client {
private:
	string clientName;
	string socialSecurityNumber;
	string clientID;
	string clientPassword;
	int log_status;

	/*���ű�ɿ� �ʿ�*/
	ProductCollection purchasedProductList; //�����ڿ��� �߰�

	/*�Ǹ� ��ɿ� �ʿ�*/
	ProductCollection soldProductList; //�Ǹ� ����

public:

	void createClient(string& name, string& SSN, string& ID, string& password);
	string getClientID();         //� ���� �������� ���� ��� ���� ��ȯ�ϵ��� ��������ϴ�.
	string getClientSSN();
	string getClientName();
	string getClientPW();
	bool getlog_status();
	void set_log(int log_status); // �α��λ��¸� �ٲٴ� �Լ�

	/*���� ���*/
	void addPurchaseInformation(Product* product); 
	ProductCollection getPurchasedProductList();   

	/*�Ǹ� ���*/
	void addSoldProduct(Product* product);
	ProductCollection getSoldProductList();
};

//ClientCollection Ŭ���� ����
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

