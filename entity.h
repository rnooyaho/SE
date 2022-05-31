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
	bool log_status;
public:
	void createClient(string& name, string& SSN, string& ID, string& password);
	string getClientID();         //� ���� �������� ���� ��� ���� ��ȯ�ϵ��� ��������ϴ�.
	string getClientSSN();
	string getClientName();
	string getClientPW();
	bool getlog();
	void set_log(bool log_status); // �α��λ��¸� �ٲٴ� �Լ�
};

class ClientCollection {
private:

public:
	vector<Client*> clients; //�ϴ��� �ð��� �˹��ؼ� public���� ���Ҵµ� private���� ���������Դϴ�!
	int findClientIndex(string ClientName); // �̸��� ���� ���̵� ã��
	int findClientIndex();  //�α��� ���� ���̵� ã��
	void addClient(Client* client);
	void deleteClient(string ClientName);
	void printClient();
	int Login(string ID, string PW);
};







