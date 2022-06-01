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

class Product {
private:
	string sellerID; //�߰�
	string productName;
	string productCompanyName;
	int cost;
	int quantityLeft;
	int quantitysold;
	int averageScore;

	//�߰�
	Client* seller;
	//int margin;

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
	Product(Client* actor, string productName, string companyName, int cost, int quantityLeft); //�Ǹ� ���� ���

	void getProductDetails(string& ID, string& name, string& companyName, int& productCost, int& left, float& score);
	string getProductName();//�ʿ��ؼ� �߰���
	string getName(); //���� �߰��� �Լ�. Search���� �ʿ���.
	string getSellerID();
	void setScore(int score);
	void stockCorrection();


	//void createProduct(Client* actor, string productName, string companyName, int cost, int quantityLeft);
	int getQuantityLeft();
	int getQuantitySold();
	int getScore();
	int calculateProfit();
	//void getProductCostAndScore();

};


class ProductCollection {
private:
	vector<Product*> products;
public:
	Product* findProduct(string productName);
	void addProduct(Product* product);
	int getSize();
	Product* getProduct(int i);

	//�߰�
	//void deleteProduct(Product* product);
	
	void sortList();
};

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
	//ProductCollection soldOutProductList; //�� �ȸ� ���ǵ�.

public:
	/*
	Client() { // 4���� �� ���ư����� ������ ���� ������. 
		clientName = "part";
		socialSecurityNumber = "123456";
		clientID = "obs";
		clientPassword = "pw2d";
	}
	*/

	void createClient(string& name, string& SSN, string& ID, string& password);
	string getClientID();         //� ���� �������� ���� ��� ���� ��ȯ�ϵ��� ��������ϴ�.
	string getClientSSN();
	string getClientName();
	string getClientPW();
	bool getlog_status();
	void set_log(int log_status); // �α��λ��¸� �ٲٴ� �Լ�
	//void deleteClient(); //��� �� �Ǹŷ� ����

	/*���� ���*/
	void addPurchaseInformation(Product* product); //�����ڿ��� �߰�
	ProductCollection getPurchasedProductList();   //�����ڿ��� �߰�

	/*�Ǹ� ���*/
	void addSoldProduct(Product* product);
	ProductCollection getSoldProductList();
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

