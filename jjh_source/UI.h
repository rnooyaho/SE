#pragma once

#include <fstream>
#include <string>
#include <vector>
#include "entity.h"
using namespace std;

class AddProductUI;
class AddProduct;
class SearchProductForSaleUI;//다이어그램 변경 필요 ProductForSaleUI -> SearchProductForSaleUI
class SearchProductForSale;//다이어그램 변경 필요 ProductForSale -> SearchProductForSale
class ListSoldProductUI;
class ListSoldProduct;
class ShowStatisticsUI;
class ShowStatistics;

//3.1 판매의류등록
class AddProductUI {
public:
	void startInterface(ifstream& fin, ofstream& fout);
	void enterProductInformation(ifstream& fin, ofstream& fout, AddProduct* addproduct);
};
class AddProduct {
	Client* loginClient;
	AddProductUI* pAddProductUI;
	ProductCollection sellerproduct;
public:
	AddProduct();
	AddProduct(ProductCollection& sellerproduct, Client* curclient, ifstream& fin, ofstream& fout);
	void addNewProduct(string productname, string companyname, int productcost, int quantityleft);
	AddProductUI* getAddProductUI() { return pAddProductUI; }
	Client* getClientInfo() { return loginClient; }
};


//3.2 등록 상품 조회
class SearchProductForSaleUI {
public:
	void startInterface(ifstream& fin, ofstream& fout);
	void selectProductForSale(SearchProductForSale* searchproductforsale);
};
class SearchProductForSale {
	Client* loginClient;
	SearchProductForSaleUI* pSearchProductForSaleUI;
	ProductCollection sellerproduct;
public:
	SearchProductForSale();
	SearchProductForSale(ProductCollection& sellerproduct, Client* curclient, ifstream& fin, ofstream& fout);
	void showProductForSale(SearchProductForSale* searchproductforsale);
	SearchProductForSaleUI* getSearchProductForSaleUI() { return pSearchProductForSaleUI; }
};

//3.3 판매 완료 상품 조회
class ListSoldProductUI {
public:
	void startInterface();
	void ListSoldProduct();
};
class ListSoldProduct {
public:
	void showSoldProductList();
};

//5.1 판매 상품 통계
class ShowStatisticsUI {
public:
	void startInterface();
	void showStatistics();
};
class ShowStatistics {
public:
	void showTotalSalesAndAverageScore();
};

