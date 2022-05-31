#pragma once
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
	string socialSecurityNumber;
	string clientID;
	string clientPassword;
	bool log_status;
public:
	void createClient(string& name, string& SSN, string& ID, string& password);
	string getClientID();         //어떤 정보 접근할지 몰라서 모든 값들 반환하도록 만들었습니다.
	string getClientSSN();
	string getClientName();
	string getClientPW();
	bool getlog();
	void set_log(bool log_status); // 로그인상태를 바꾸는 함수
};

class ClientCollection {
private:

public:
	vector<Client*> clients; //일단은 시간이 촉박해서 public으로 놓았는데 private으로 수정예정입니다!
	int findClientIndex(string ClientName); // 이름을 통해 아이디 찾기
	int findClientIndex();  //로그인 중인 아이디 찾기
	void addClient(Client* client);
	void deleteClient(string ClientName);
	void printClient();
	int Login(string ID, string PW);
};







