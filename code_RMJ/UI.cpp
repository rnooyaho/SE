#include "UI.h"

//4.1. ��ǰ ���� �˻� ����
void SearchUI::startInterface(ifstream& fin)
{
	string productName;
	fin >> productName;
	this->productName = productName;
}
void SearchUI::enterProductName(Search* search, vector<Product*> products, ofstream& fout) //��ǰ ���� �˻� 2.
{
	selected = search->searchProduct(productName, products,fout);
}
Product* SearchUI::selectPurchase()
{
	return selected;
}

Search::Search(ifstream& fin, vector<Product*> products, Product* selected, ofstream& fout) {//��ǰ ���� �˻� 0.
	fout << "4.1. ��ǰ ���� �˻�" << endl;

	searchUI = new SearchUI;
	searchUI->startInterface(fin); //��ǰ ���� �˻� 1.
	searchUI->enterProductName(this, products,fout); //��ǰ ���� �˻� 2.

	selected = searchUI->selectPurchase();
}
Product* Search::searchProduct(string productName, vector<Product*> products, ofstream& fout) //��ǰ ���� �˻� 2.1.
{
	for (int i = 0; i < products.size(); ++i)
	{
		if (products[i]->getName() == productName)
		{
			products[i]->getProductDetails(fout); //��ǰ ���� �˻� 2.1.1.
			return products[i];
		}
	}
}


//4.2. ��ǰ ���� ����
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
	fout << "4.2. ��ǰ ����\n";
	this->product = product;
	this->actor = actor;
	purchaseUI = new PurchaseUI;
	purchaseUI->startInterface(this); //4.1.

	fout << "<" << actor->getClientID() << " " << product->getProductName() << endl;
}
void Purchase::purchaseProduct()
{
	actor->addPurchaseInformation(this->product);//4.1.1.1.1.�����ڿ��� ���� ���� �߰�
	product->stockCorrection(); //4.1.1.1.2.��� ����
}

//4.3. ��ǰ ���� ���� ��ȸ ����
ShowShopping::ShowShopping(Purchaser* actor, ofstream& fout)
{
	vector<Product*> list;
	fout << "4.3. ��ǰ ���� ���� ��ȸ\n";
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

//4.4. ���Ÿ����� ����
void SatisfactionScoreUI::startInterface(ifstream& fin, string& productName, int& score)
{
	//��ǰ��� ���� ������ �Է�
	fin >> productName >> score;
}
SatisfactionScore::SatisfactionScore(ifstream& fin, Purchaser* actor, ofstream& fout)
{
	string productName;
	int score;
	SatisfactionScoreUI* UI = new SatisfactionScoreUI;
	UI->startInterface(fin, productName, score);

	//���Ͽ� ����
	fout << "4.4. ��ǰ ���� ������ ��\n";
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