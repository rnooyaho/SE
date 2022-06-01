#pragma once
#include <iostream>
#include<algorithm>
#include "UI.h"
//1.1 인터페이스 출력
void CreateClientAccountUI::interface(ofstream& fout) {
	fout << "1.1. 회원가입" << endl;


}
// 1.1 인터페이스에서 정보 입력
Client* CreateClientAccountUI::enterClientInformation(ifstream& fin, ofstream& fout) {
	string name;
	string SSN;
	string ID;
	string PW;
	fin >> name >> SSN >> ID >> PW;
	Client* newuser = new Client;
	newuser->createClient(name, SSN, ID, PW);
	fout << "> " << name << " " << SSN << " " << ID << " " << PW << " " << "\n";

	return newuser;
};

// 1.1 입력받은 정보를 통해 client콜랙션에 회원정보 추가
void CreateClientAccount::addNewClient(ifstream& fin, ClientCollection& ALLclients, ofstream& fout) {
	Client* CCA = new Client; //회원가입할 client객체 생성
	CCA_UI = new CreateClientAccountUI;
	CCA_UI->interface(fout); //인터페이스 출력
	CCA = CCA_UI->enterClientInformation(fin, fout); //입력받은 회원정보 출력

	ALLclients.addClient(CCA);
}

// 1.2 인터페이스 출력

void DeleteClientAccountUI::interface(ofstream& fout) {
	fout << "1.2. 회원탈퇴" << endl;
}
//1.2 로그인중인 회원아이디 탈퇴 
void DeleteClientAccountUI::deleteClientAccount(ClientCollection& ALLclients, ofstream& fout) {

	Client* delete_Client = new Client;

	delete_Client = ALLclients.LoginID(); //로그인중인 회원 객체를 탈퇴하기 위해 불러온다.

	fout << "> " << delete_Client->getClientID() << " " << "\n"; // 회원탈퇴할 아이디 출력

	ALLclients.deleteClient(delete_Client);
};

// 1.2 client콜랙션에 회원정보 삭제
void DeleteClientAccount::deleteClient(ifstream& fin, ClientCollection& ALLclients, ofstream& fout) {

	DCA_UI = new DeleteClientAccountUI;
	DCA_UI->interface(fout); //인터페이스 출력
	DCA_UI->deleteClientAccount(ALLclients, fout); //탈퇴한 회원아이디 출력

}




// 2.1 로그인 인터페이스 출력
void LoginUI::interface(ofstream& fout) {
	fout << "2.1. 로그인" << endl;


}
// 2.1 로그인 ID,PW  정보 입력
string* LoginUI::selectLogin(ifstream& fin, ofstream& fout) {
	string ID;
	string PW;
	static string ID_PW[2];

	fin >> ID >> PW;

	ID_PW[0] = ID;
	ID_PW[1] = PW;

	fout << "> " << ID << " " << PW << " " << "\n";

	return ID_PW;
};

// 2.1 입력받은 정보를 통해 로그인 시도 
void Login::tryLogin(ifstream& fin, ClientCollection& ALLclients, ofstream& fout)
{

	Login_UI = new LoginUI;
	Login_UI->interface(fout); //인터페이스 출력
	//ID,PW값 받기

	string* PW = Login_UI->selectLogin(fin, fout);

	cout << "Id, PW =" << PW[0] << "  " << PW[1] << endl;

	// ID,PW 일치 하는 계정 log_status값 0에서 1로 변경하기 위해 호출
	Client* Login_Client = new Client;

	Login_Client = ALLclients.Login(PW[0], PW[1]); //로그인할 아이디 객체
	Login_Client->set_log(1); // 로그인상태로 변경

}



// 2.2 로그아웃 인터페이스 출력
void LogoutUI::interface(ofstream& fout) {
	fout << "2.2. 로그아웃" << endl;


}
// 2.2 로그아웃  (로그인 상태인 client의 log_status를 1에서 0으로 바꾼다.
void LogoutUI::selectLogout(ClientCollection& ALLclients, ofstream& fout) {
	Client* Logout_Client = new Client;

	Logout_Client = ALLclients.LoginID(); //로그인중인 회원 객체 
	Logout_Client->set_log(0); // 로그인상태로 변경


	fout << "> " << Logout_Client->getClientID() << " " << "\n"; // 로구아웃 한 아이디 출력

};


// 2.2 cl
void Logout::tryLogout(ClientCollection& ALLclients, ofstream& fout) {

	Logout_UI = new LogoutUI;
	Logout_UI->interface(fout); //인터페이스 출력
	Logout_UI->selectLogout(ALLclients, fout); //탈퇴한 회원아이디 출력

}
/*
3.1. 판매 의류 등록
입력 : 3 1 [상품명] [제작회사명] [가격] [수량]
출력 : > [상품명] [제작회사명] [가격] [수량]
*/
/*Boundary*/
void AddProductUI::startInterface(ifstream& fin, string& productName, string& companyName, int& cost, int& quantityLeft, ofstream& fout)
{
	fout << "3.1. 판매 의류 등록" << endl;
	fin >> productName >> companyName >> cost >> quantityLeft;
}
void AddProductUI::printNewProduct(ofstream& fout, Product* product)
{
	string sellerID; //안 쓰지만 받아와야함
	string productName;
	string companyName;
	int productCost;
	int quantityLeft;
	float score; //안 쓰지만 받아와야함

	product->getProductDetails(sellerID, productName, companyName, productCost, quantityLeft, score);
	fout << "> " << productName << " " << companyName << " " << productCost << " " << quantityLeft << " " << "\n";

}
/*control*/
void AddProduct::run(ifstream& fin, Client* actor, ProductCollection& totalProduct, ofstream& fout)
{
	//1.interface불러와서 정보 입력 받기
	//2. 상품 생성하기 
	//3. actor에 판매중인 상품 목록 추가
	//4. 전체 상품 리스트에 새 상품 추가.
	//5. fout으로 상품 정보 출력. 

	string productName, companyName;
	int cost, quantityLeft;

	AddProductUI* UI = new AddProductUI;
	UI->startInterface(fin, productName, companyName, cost, quantityLeft, fout);
	Product* newProduct = new Product(actor, productName, companyName, cost, quantityLeft);
	actor->addSoldProduct(newProduct);
	totalProduct.addProduct(newProduct);//전체 상품 리스트에 등록. 

	UI->printNewProduct(fout, newProduct);
}


/*
3.2. 등록 상품 조회
입력 : 3 2
출력 : > { [상품명] [제작회사명] [가격] [수량] }*
*/
/*Boundary*/
void ProductForSaleUI::startInterface(ofstream& fout)
{
	fout << "3.2. 등록 상품 조회" << endl;
}
void ProductForSaleUI::showProductForSales(ProductCollection products, ofstream& fout)
{
	if (products.getSize() == 0)
	{
		cout << "판매 상품 없음" << endl;
		return;
	}
	string sellerID;
	string productName;
	string companyName;
	int productCost;
	int quantityLeft;
	float score;

	products.sortList();

	for (int i = 0; i < products.getSize(); ++i)
	{
		if (products.getProduct(i)->getQuantityLeft() != 0) //재고가 0이 아니면
		{
			products.getProduct(i)->getProductDetails(sellerID, productName, companyName, productCost, quantityLeft, score);
			fout << "> " << sellerID << " " << productName << " " << companyName << " " << productCost << " " << quantityLeft << " " << score << "\n";
		}
	}
}
/*control*/
void ProductForSale::run(Client* actor, ofstream& fout)
{
	ProductForSaleUI* UI = new ProductForSaleUI;
	UI->startInterface(fout);
	ProductCollection list = actor->getSoldProductList();
	UI->showProductForSales(list, fout);
}

/*
3.3. 판매 완료 상품 조회
입력 : 3 3
출력 : > { [상품명] [제작회사명] [가격] [판매된 수량] [평균 구매만족도] }*

*/
/*Boundary*/
void ListSoldProductUI::startInterface(ofstream& fout)
{
	fout << "3.3. 판매 완료 상품 조회" << endl;
}
void ListSoldProductUI::showSoldProductList(ProductCollection products, ofstream& fout)
{
	if (products.getSize() == 0)
	{
		cout << "판매 완료 상품 없음" << endl;
		return;
	}
	string sellerID;
	string productName;
	string companyName;
	int productCost;
	int quantityLeft;
	float score;
	int quantitySold;

	products.sortList();//오름차순 출력

	for (int i = 0; i < products.getSize(); ++i)
	{
		if (products.getProduct(i)->getQuantityLeft() == 0) //재고가 0이면
		{
			products.getProduct(i)->getProductDetails(sellerID, productName, companyName, productCost, quantityLeft, score);
			quantitySold = products.getProduct(i)->getQuantitySold();
			fout << "> " << productName << " " << companyName << " " << productCost << " " << quantitySold << " " << score << "\n";
		}
	}
}
/*control*/
void ListSoldProduct::run(Client* actor, ofstream& fout)
{
	ListSoldProductUI* UI = new ListSoldProductUI;
	UI->startInterface(fout);
	ProductCollection list = actor->getSoldProductList();
	UI->showSoldProductList(list, fout);
}

/*
5.1. 판매 상품 통계
입력 : 5 1
출력 : > { [상품명] [상품 판매 총액] [평균 구매만족도] }*
*/
/*Boundary*/
void ShowStatisticsUI::startInterface(ofstream& fout)
{
	fout << "5.1. 판매 상품 통계" << endl;
}
void ShowStatisticsUI::showStatistics(ProductCollection list, ofstream& fout)
{
	string productName;
	int totalCost;
	int score;

	for (int i = 0; i < list.getSize(); ++i)
	{
		productName = list.getProduct(i)->getName();
		totalCost = list.getProduct(i)->calculateProfit();
		score = list.getProduct(i)->getScore();
		fout << productName << " " << totalCost << " " << score << "\n";
	}
}
/*control*/
void ShowStatistic::run(Client* actor, ofstream& fout)
{
	ShowStatisticsUI* UI = new ShowStatisticsUI;
	UI->startInterface(fout);

	ProductCollection list = actor->getSoldProductList();
	UI->showStatistics(list, fout);

}

//4.1. 상품 정보 검색 구현
void SearchUI::startInterface(ifstream& fin, ofstream& fout)
{
	fout << "4.1. 상품 정보 검색" << endl;

	string productName;
	fin >> productName;
	this->productName = productName;
}
void SearchUI::enterProductName(Search* search, ProductCollection products, ofstream& fout) //상품 정보 검색 2.
{
	string sellerID;
	string name;
	string companyName;
	int productCost;
	int quantityLeft;
	float score;

	this->selected = search->searchProduct(this->productName, products);
	selected->getProductDetails(sellerID, name, companyName, productCost, quantityLeft, score);
	fout << "> " << sellerID << " " << productName << " " << companyName << " " << productCost << " " << quantityLeft << " "<<score<<"\n";
}
Product* SearchUI::selectPurchase()
{
	return selected;
}

Product* Search::run(ifstream& fin, ProductCollection products, Product*& selected, ofstream& fout) //상품 정보 검색 0.
{

	searchUI = new SearchUI;
	searchUI->startInterface(fin, fout); //상품명 입력 받음
	searchUI->enterProductName(this, products, fout); //입력받은 상품 정보 출력 

	selected = searchUI->selectPurchase(); //구매 버튼 반환.
	return selected;
}
Product* Search::searchProduct(string productName, ProductCollection products) //상품 정보 검색 2.1.
{
	Product* product = products.findProduct(productName);
	//product->getProductDetails(); 
	return product;
}


/*
4.2. 상품 구매 구현
출력 예시
4.2. 상품 구매
> mbc hat
남은 수량 0인거 판매 완료로 넘어가게 구현해야되는데..흠.
*/
void PurchaseUI::startInterface(Product* product, Client* actor, ofstream& fout, Purchase* purchase) //4.1.
{
	this->purchase = purchase;
	purchaseProduct();
	fout << "> " << product->getSellerID() << " " << product->getProductName() << endl; //판매자 아이디와 상품명.
}
void PurchaseUI::purchaseProduct() //4.1.1.
{
	purchase->purchaseProduct();
}
Client* Purchase::run(Product* product, Client* actor, ofstream& fout)
{
	fout << "4.2. 상품 구매\n";
	this->product = product;
	this->actor = actor;
	purchaseUI = new PurchaseUI;
	purchaseUI->startInterface(product, actor, fout, this); //4.1.

	return actor;
}
void Purchase::purchaseProduct()
{
	actor->addPurchaseInformation(this->product);//4.1.1.1.1.구매자에게 구매 정보 추가
	product->stockCorrection(); //4.1.1.1.2.재고 수정
}

/*
4.3. 상품 구매 내역 조회 구현
출력 예시
4.3. 상품 구매 내역 조회
> mbc hat chulsoo 2000 1
*/
void ShowShopping::run(Client* actor, ofstream& fout)
{
	ProductCollection list;
	ShowShoppingListUI UI;
	list = actor->getPurchasedProductList(); //구매 내역 불러오기.

	UI.startInterface(list, fout); //구매내역 interface로 전달. 
}
void ShowShoppingListUI::startInterface(ProductCollection list, ofstream& fout)
{
	fout << "4.3. 상품 구매 내역 조회" << endl;
	if (list.getSize() == 0)
	{
		cout << "구매 내역 없음" << endl;
		return;
	}
	string sellerID;
	string productName;
	string companyName;
	int productCost;
	int quantityLeft;
	float score;
	
	list.sortList();

	for (int i = 0; i < list.getSize(); ++i)
	{
		list.getProduct(i)->getProductDetails(sellerID, productName, companyName, productCost, quantityLeft, score);
		fout << "> " << sellerID << " " << productName << " " << companyName << " " << productCost << " " << quantityLeft << " "<<score<<"\n";
	}
}

/*
4.4. 구매만족도 구현
출력 예시
4.4. 상품 구매 만족도 평가
> mbc hat 3
*/
void SatisfactionScoreUI::startInterface(ifstream& fin, string& productName, int& score, ofstream& fout)
{
	fout << "4.4. 상품 구매 만족도 평가\n";
	fin >> productName >> score; //상품명과 구매 만족도 입력 받음
}
void SatisfactionScoreUI::printScore(string sellerID, string productName, int score, ofstream& fout)
{
	fout << "> " << sellerID << " " << productName << " " << score << "\n";
}
void SatisfactionScore::run(ifstream& fin, Client* actor, ofstream& fout)
{
	string productName;
	int score;
	SatisfactionScoreUI* UI = new SatisfactionScoreUI;
	UI->startInterface(fin, productName, score, fout); //UI에서 제품명과 만족도 입력. 

	ProductCollection list;
	list = actor->getPurchasedProductList(); //구매 리스트 불러오기.
	Product* product;
	product = list.findProduct(productName); //제품명으로 제품 찾기.
	product->setScore(score); //평균 만족도 갱신

	UI->printScore(product->getSellerID(), productName, score, fout); //UI에서 판매자 ID, 제품명, 평균 만족도 출력.

}

