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

class Product {
private:
	string sellerID; //추가
	string productName;
	string productCompanyName;
	int cost;
	int quantityLeft;
	int quantitysold;
	int averageScore;

	//추가
	Client* seller;
	//int margin;

public:
	/*
	Product() { //실험용으로 만든 생성자. push 전에 지우기. 
		sellerID = "mbc";
		productName = "hat";
		productCompanyName = "chulsoo";
		cost = 2000;
		quantityLeft = 2;
		quantitysold = 0;
		averageScore = 0.0; //구매만족도 초기값은 0. 이것만 남겨두기. 
	}
	*/
	Product(Client* actor, string productName, string companyName, int cost, int quantityLeft); //판매 물건 등록

	void getProductDetails(string& ID, string& name, string& companyName, int& productCost, int& left, float& score);
	string getProductName();//필요해서 추가함
	string getName(); //새로 추가한 함수. Search에서 필요함.
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

	//추가
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

	/*구매기능에 필요*/
	ProductCollection purchasedProductList; //구매자에서 추가

	/*판매 기능에 필요*/
	ProductCollection soldProductList; //판매 물건
	//ProductCollection soldOutProductList; //다 팔린 물건들.

public:
	/*
	Client() { // 4번대 잘 돌아가는지 보려고 만든 생성자. 
		clientName = "part";
		socialSecurityNumber = "123456";
		clientID = "obs";
		clientPassword = "pw2d";
	}
	*/

	void createClient(string& name, string& SSN, string& ID, string& password);
	string getClientID();         //어떤 정보 접근할지 몰라서 모든 값들 반환하도록 만들었습니다.
	string getClientSSN();
	string getClientName();
	string getClientPW();
	bool getlog_status();
	void set_log(int log_status); // 로그인상태를 바꾸는 함수
	//void deleteClient(); //재고 및 판매량 수정

	/*구매 기능*/
	void addPurchaseInformation(Product* product); //구매자에서 추가
	ProductCollection getPurchasedProductList();   //구매자에서 추가

	/*판매 기능*/
	void addSoldProduct(Product* product);
	ProductCollection getSoldProductList();
};

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

