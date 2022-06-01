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
	int log_status;

	// ProductCollection purchasedProductList; //구매자에서 추가
public:
	void createClient(string& name, string& SSN, string& ID, string& password);
	string getClientID();         //어떤 정보 접근할지 몰라서 모든 값들 반환하도록 만들었습니다.
	string getClientSSN();
	string getClientName();
	string getClientPW();
	bool getlog_status();
	void set_log(int log_status); // 로그인상태를 바꾸는 함수


	//void addPurchaseInformation(Product* product); //구매자에서 추가
	//ProductCollection getPurchasedProductList();   //구매자에서 추가
};

class ClientCollection {
private:
	vector<Client*> clients; //일단은 시간이 촉박해서 public으로 놓았는데 private으로 수정예정입니다!
public:
	int findClientIndex(string ClientName); // 이름을 통해 아이디 인덱스 찾기 // 1.2구현을 위해 사용
	Client* Login(string ID, string PW);  //로그인 할 아이디의 로그인상태값 변경을 위해 호출 // 2.1로그인에서!
	void addClient(Client* client);  // 1.1회원가입
	void deleteClient(Client* client); // 1.2 회원탈퇴
	void printClient(); //나중에 삭제할 함수. 총 회원수를 구현중에 확인하려고 넣었습니다.
	Client* LoginID(); //로그인되어있는 객체 반환

};







