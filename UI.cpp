#pragma once
#include <iostream>
#include<algorithm>
#include "UI.h"
#include <vector>
#include <algorithm>
//1.1 �������̽� ���
void CreateClientAccountUI::interface(ofstream& fout) {
	fout << "1.1. ȸ������" << endl;

	
}
// 1.1 �������̽����� ���� �Է�
Client* CreateClientAccountUI::enterClientInformation(ifstream& fin, ofstream& fout) {
	string name;
	string SSN;
	string ID;
	string PW;
	fin >> name >> SSN >> ID >> PW;
	Client* newuser = new Client;
	newuser->createClient(name, SSN, ID, PW);
	fout << "> " << name << " " << SSN << " " << ID << " " << PW << " "  << "\n";

	return newuser;
};

// 1.1 �Է¹��� ������ ���� client�ݷ��ǿ� ȸ������ �߰�
void CreateClientAccount::addNewClient(ifstream& fin, ClientCollection& ALLclients, ofstream& fout){
	Client* CCA = new Client; //ȸ�������� client��ü ����
	CCA_UI = new CreateClientAccountUI;
	CCA_UI->interface(fout); //�������̽� ���
	CCA = CCA_UI->enterClientInformation(fin,fout); //�Է¹��� ȸ������ ���

	ALLclients.addClient(CCA);
}

// 1.2 �������̽� ���

void DeleteClientAccountUI::interface(ofstream& fout) {
	fout << "1.2. ȸ��Ż��" << endl;
}
//1.2 �α������� ȸ�����̵� Ż�� 
void DeleteClientAccountUI::deleteClientAccount(ClientCollection &ALLclients, ofstream& fout) {
	
	Client* delete_Client = new Client;

	delete_Client = ALLclients.LoginID(); //�α������� ȸ�� ��ü�� Ż���ϱ� ���� �ҷ��´�.

	fout << "> " << delete_Client->getClientID() << " " << "\n"; // ȸ��Ż���� ���̵� ���

	ALLclients.deleteClient(delete_Client);
};

// 1.2 client�ݷ��ǿ� ȸ������ ����
void DeleteClientAccount::deleteClient(ifstream& fin, ClientCollection& ALLclients, ofstream& fout) {
	
	DCA_UI = new DeleteClientAccountUI;
	DCA_UI->interface(fout); //�������̽� ���
	DCA_UI->deleteClientAccount(ALLclients, fout); //Ż���� ȸ�����̵� ���

}




// 2.1 �α��� �������̽� ���
void LoginUI::interface(ofstream& fout) {
	fout << "2.1. �α���" << endl;


}
// 2.1 �α��� ID,PW  ���� �Է�
string *LoginUI::selectLogin(ifstream& fin, ofstream& fout) {
	string ID;
	string PW;
	static string ID_PW[2];
	
	fin >>  ID >> PW;

	ID_PW[0] = ID;
	ID_PW[1] = PW;

	fout << "> " << ID << " " << PW << " " << "\n";

	return ID_PW;
};

// 2.1 �Է¹��� ������ ���� �α��� �õ� 
void Login::tryLogin(ifstream& fin, ClientCollection& ALLclients, ofstream& fout) 
{

	Login_UI = new LoginUI;
	Login_UI->interface(fout); //�������̽� ���
	//ID,PW�� �ޱ�

	string* PW = Login_UI->selectLogin(fin, fout);

	cout << "Id, PW =" <<  PW[0]<< "  " << PW[1] << endl;

	// ID,PW ��ġ �ϴ� ���� log_status�� 0���� 1�� �����ϱ� ���� ȣ��
	Client* Login_Client = new Client;

	Login_Client = ALLclients.Login(PW[0],PW[1]); //�α����� ���̵� ��ü
	Login_Client->set_log(1); // �α��λ��·� ����

}



// 2.2 �α׾ƿ� �������̽� ���
void LogoutUI::interface(ofstream& fout) {
	fout << "2.2. �α׾ƿ�" << endl;


}
// 2.2 �α׾ƿ�  (�α��� ������ client�� log_status�� 1���� 0���� �ٲ۴�.
void LogoutUI::selectLogout(ClientCollection& ALLclients, ofstream& fout) {
	Client* Logout_Client = new Client;

	Logout_Client = ALLclients.LoginID(); //�α������� ȸ�� ��ü 
	Logout_Client->set_log(0); // �α��λ��·� ����
	
	
	fout << "> " << Logout_Client->getClientID() << " " << "\n"; // �α��ƿ� �� ���̵� ���

};


// 2.2 cl
void Logout::tryLogout(ClientCollection& ALLclients, ofstream& fout) {

	Logout_UI = new LogoutUI;
	Logout_UI->interface(fout); //�������̽� ���
	Logout_UI->selectLogout(ALLclients, fout); //Ż���� ȸ�����̵� ���

}


//4.1. ��ǰ ���� �˻� ����
void SearchUI::startInterface(ifstream& fin, ofstream& fout)
{
	fout << "4.1. ��ǰ ���� �˻�" << endl;

	string productName;
	fin >> productName;
	this->productName = productName;
}
void SearchUI::enterProductName(Search* search, ProductCollection products, ofstream& fout) //��ǰ ���� �˻� 2.
{
	string sellerID;
	string name;
	string companyName;
	int productCost;
	int quantityLeft;
	float score;

	this->selected = search->searchProduct(this->productName, products);
	selected->getProductDetails(sellerID, name, companyName, productCost, quantityLeft);
	fout << "> " << sellerID << " " << productName << " " << companyName << " " << productCost << " " << quantityLeft << "\n";
}
Product* SearchUI::selectPurchase()
{
	return selected;
}

Product* Search::run(ifstream& fin, ProductCollection products, Product*& selected, ofstream& fout) //��ǰ ���� �˻� 0.
{

	searchUI = new SearchUI;
	searchUI->startInterface(fin, fout); //��ǰ�� �Է� ����
	searchUI->enterProductName(this, products, fout); //�Է¹��� ��ǰ ���� ��� 

	selected = searchUI->selectPurchase(); //���� ��ư ��ȯ.
	return selected;
}
Product* Search::searchProduct(string productName, ProductCollection products) //��ǰ ���� �˻� 2.1.
{
	Product* product = products.findProduct(productName);
	//product->getProductDetails(); 
	return product;
}


/*
4.2. ��ǰ ���� ����
��� ����
4.2. ��ǰ ����
> mbc hat
*/
void PurchaseUI::startInterface(Product* product, Client* actor, ofstream& fout, Purchase* purchase) //4.1.
{
	this->purchase = purchase;
	purchaseProduct();
	fout << "> " << product->getSellerID() << " " << product->getProductName() << endl; //�Ǹ��� ���̵�� ��ǰ��.
}
void PurchaseUI::purchaseProduct() //4.1.1.
{
	purchase->purchaseProduct();
}
Client* Purchase::run(Product* product, Client* actor, ofstream& fout)
{
	fout << "4.2. ��ǰ ����\n";
	this->product = product;
	this->actor = actor;
	purchaseUI = new PurchaseUI;
	purchaseUI->startInterface(product, actor, fout, this); //4.1.

	return actor;
}
void Purchase::purchaseProduct()
{
	actor->addPurchaseInformation(this->product);//4.1.1.1.1.�����ڿ��� ���� ���� �߰�
	product->stockCorrection(); //4.1.1.1.2.��� ����
}

/*
4.3. ��ǰ ���� ���� ��ȸ ����
��� ����
4.3. ��ǰ ���� ���� ��ȸ
> mbc hat chulsoo 2000 1
*/
void ShowShopping::run(Client* actor, ofstream& fout)
{
	ProductCollection list;
	ShowShoppingListUI UI;
	list = actor->getPurchasedProductList(); //���� ���� �ҷ�����.

	UI.startInterface(list, fout); //���ų��� interface�� ����. 
}
void ShowShoppingListUI::startInterface(ProductCollection list, ofstream& fout)
{
	fout << "4.3. ��ǰ ���� ���� ��ȸ" << endl;
	if (list.getSize() == 0)
	{
		cout << "���� ���� ����" << endl;
		return;
	}
	string sellerID;
	string productName;
	string companyName;
	int productCost;
	int quantityLeft;

	for (int i = 0; i < list.getSize(); ++i)
	{
		list.getProduct(i)->getProductDetails(sellerID, productName, companyName, productCost, quantityLeft);
		fout << "> " << sellerID << " " << productName << " " << companyName << " " << productCost << " " << quantityLeft << "\n";
	}
}

/*
4.4. ���Ÿ����� ����
��� ����
4.4. ��ǰ ���� ������ ��
> mbc hat 3
*/
void SatisfactionScoreUI::startInterface(ifstream& fin, string& productName, int& score, ofstream& fout)
{
	fout << "4.4. ��ǰ ���� ������ ��\n";
	fin >> productName >> score; //��ǰ��� ���� ������ �Է� ����
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
	UI->startInterface(fin, productName, score, fout); //UI���� ��ǰ��� ������ �Է�. 

	ProductCollection list;
	list = actor->getPurchasedProductList(); //���� ����Ʈ �ҷ�����.
	Product* product;
	product = list.findProduct(productName); //��ǰ������ ��ǰ ã��.
	product->setScore(score); //��� ������ ����

	UI->printScore(product->getSellerID(), productName, score, fout); //UI���� �Ǹ��� ID, ��ǰ��, ��� ������ ���.

}








