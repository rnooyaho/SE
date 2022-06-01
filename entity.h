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

	// ProductCollection purchasedProductList; //�����ڿ��� �߰�
public:
	void createClient(string& name, string& SSN, string& ID, string& password);
	string getClientID();         //� ���� �������� ���� ��� ���� ��ȯ�ϵ��� ��������ϴ�.
	string getClientSSN();
	string getClientName();
	string getClientPW();
	bool getlog_status();
	void set_log(int log_status); // �α��λ��¸� �ٲٴ� �Լ�


	//void addPurchaseInformation(Product* product); //�����ڿ��� �߰�
	//ProductCollection getPurchasedProductList();   //�����ڿ��� �߰�
};

class ClientCollection {
private:
	vector<Client*> clients; //�ϴ��� �ð��� �˹��ؼ� public���� ���Ҵµ� private���� ���������Դϴ�!
public:
	int findClientIndex(string ClientName); // �̸��� ���� ���̵� �ε��� ã�� // 1.2������ ���� ���
	Client* Login(string ID, string PW);  //�α��� �� ���̵��� �α��λ��°� ������ ���� ȣ�� // 2.1�α��ο���!
	void addClient(Client* client);  // 1.1ȸ������
	void deleteClient(Client* client); // 1.2 ȸ��Ż��
	void printClient(); //���߿� ������ �Լ�. �� ȸ������ �����߿� Ȯ���Ϸ��� �־����ϴ�.
	Client* LoginID(); //�α��εǾ��ִ� ��ü ��ȯ

};







