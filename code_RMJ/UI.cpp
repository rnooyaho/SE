#include "UI.h"

//4.1. 상품 정보 검색 구현
void SearchUI::startInterface(ifstream& fin)
{
	string productName;
	fin >> productName;
	this->productName = productName;
}
void SearchUI::enterProductName(Search* search, vector<Product*> products, ofstream& fout) //상품 정보 검색 2.
{
	selected = search->searchProduct(productName, products,fout);
}
Product* SearchUI::selectPurchase()
{
	return selected;
}

Search::Search(ifstream& fin, vector<Product*> products, Product* selected, ofstream& fout) {//상품 정보 검색 0.
	fout << "4.1. 상품 정보 검색" << endl;

	searchUI = new SearchUI;
	searchUI->startInterface(fin); //상품 정보 검색 1.
	searchUI->enterProductName(this, products,fout); //상품 정보 검색 2.

	selected = searchUI->selectPurchase();
}
Product* Search::searchProduct(string productName, vector<Product*> products, ofstream& fout) //상품 정보 검색 2.1.
{
	for (int i = 0; i < products.size(); ++i)
	{
		if (products[i]->getName() == productName)
		{
			products[i]->getProductDetails(fout); //상품 정보 검색 2.1.1.
			return products[i];
		}
	}
}


//4.2. 상품 구매 구현
void PurchaseUI::startInterface(Purchase* purchase) //4.1.
{
	this->purchase = purchase;
	purchaseProduct();
}
void PurchaseUI::purchaseProduct() //4.1.1.
{
	purchase->purchaseProduct();
}
Purchase::Purchase(Product* product, Purchaser* actor, ofstream& fout)
{
	fout << "4.2. 상품 구매\n";
	this->product = product;
	this->actor = actor;
	purchaseUI = new PurchaseUI;
	purchaseUI->startInterface(this); //4.1.

	fout << "<" << actor->getClientID() << " " << product->getProductName() << endl;
}
void Purchase::purchaseProduct()
{
	actor->addPurchaseInformation(this->product);//4.1.1.1.1.구매자에게 구매 정보 추가
	product->stockCorrection(); //4.1.1.1.2.재고 수정
}

//4.3. 상품 구매 내역 조회 구현
ShowShopping::ShowShopping(Purchaser* actor, ofstream& fout)
{
	vector<Product*> list;
	fout << "4.3. 상품 구매 내역 조회\n";
	list = actor->getPurchasedProductList(); //1.
	for (int i = 0; i < list.size(); ++i)
	{
		list[i]->getProductDetails(fout); //2.
	}

}
void ShowShoppingListUI::startInterface(ofstream& fout)
{
	fout << "\n";
}

//4.4. 구매만족도 구현
void SatisfactionScoreUI::startInterface(ifstream& fin, string& productName, int& score)
{
	//상품명과 구매 만족도 입력
	fin >> productName >> score;
}
SatisfactionScore::SatisfactionScore(ifstream& fin, Purchaser* actor, ofstream& fout)
{
	string productName;
	int score;
	SatisfactionScoreUI* UI = new SatisfactionScoreUI;
	UI->startInterface(fin, productName, score);

	//파일에 쓰기
	fout << "4.4. 상품 구매 만족도 평가\n";
	vector<Product*> list;
	list = actor->getPurchasedProductList();
	int i;
	for (i = 0; i < list.size(); ++i)
	{
		if (list[i]->getName() == productName)
			break;
	}
	list[i]->setScore(score);
	fout << "< " << actor->getClientID() << " " << productName << " " << score << "\n";
}