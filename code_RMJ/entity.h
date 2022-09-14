#pragma once
#include <fstream>
#include <string>
#include <vector>
using namespace std;
//전방 선언
class Client;
class Product;
class ProductCollection;
class ClientCollection;

//Product 클래스 선언
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

	Product(Client* actor, string productName, string companyName, int cost, int quantityLeft); //판매 물건 등록

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

//ProductCollection 클래스 선언
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

//Client 클래스 선언
class Client {
private:
	string clientName;
	string socialSecurityNumber;
	string clientID;
	string clientPassword;
	int log_status;

	/*구매기능에 필요*/
	ProductCollection purchasedProductList; //구매자에서 추가

	/*판매 기능에 필요*/
	ProductCollection soldProductList; //판매 물건

public:

	void createClient(string& name, string& SSN, string& ID, string& password);
	string getClientID();         //어떤 정보 접근할지 몰라서 모든 값들 반환하도록 만들었습니다.
	string getClientSSN();
	string getClientName();
	string getClientPW();
	bool getlog_status();
	void set_log(int log_status); // 로그인상태를 바꾸는 함수

	/*구매 기능*/
	void addPurchaseInformation(Product* product); 
	ProductCollection getPurchasedProductList();   

	/*판매 기능*/
	void addSoldProduct(Product* product);
	ProductCollection getSoldProductList();
};

//ClientCollection 클래스 선언
class ClientCollection {
private:
	vector<Client*> clients;
public:
	int findClientIndex(string ClientName); // 이름을 통해 아이디 인덱스 찾기 // 1.2구현을 위해 사용
	Client* Login(string ID, string PW);  //로그인 할 아이디의 로그인상태값 변경을 위해 호출 // 2.1로그인에서!
	void addClient(Client* client);  // 1.1회원가입
	void deleteClient(Client* client); // 1.2 회원탈퇴
	void printClient(); //나중에 삭제할 함수. 총 회원수를 구현중에 확인하려고 넣었습니다.
	Client* LoginID(); //로그인되어있는 객체 반환

};

