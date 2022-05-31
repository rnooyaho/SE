#pragma once
#include <iostream>
#include "entity.h"

//Client Ŭ���� ����Լ� ����

string Client::getClientPW()
{
	return clientPassword;
}
string Client::getClientID()
{
	return clientID;
}
string Client::getClientSSN()
{
	return socialSecurityNumber;
}
string Client::getClientName()
{
	return clientName;
}
bool Client::getlog()
{
	return log_status;
}
// ������� ��� ��� ����



//setClient�� �����ұ� �������Դϴ�.
void Client::createClient(string& name, string& SSN, string& ID, string& password)
{
	clientName = name;
	socialSecurityNumber = SSN;
	clientID = ID;
	clientPassword = password;
}
void Client::set_log(bool log_status) { //�α��� ���� �ٲٴ� �Լ�
	this->log_status = log_status;

}

//collection class ����

int ClientCollection::Login(string ID, string PW) {

	int i = 0;
	for (i = 0; i < clients.size(); i++)
	{
		if ((clients[i]->getClientID() == ID) && (clients[i] ->getClientPW ()== PW))
			//���̵� �н����� ��ġ�� �α��λ��·� ����
		{
			clients[i]->set_log(true);
			return i; //�α��� Ŭ���̾�Ʈ �ε����� ����
		}

	}
	// cout << "�α��ο� �����߽��ϴ�" ; ���߿� ����ó�� �� �ʿ� ������ ������� �߰� �ʿ�.

};

void ClientCollection::addClient(Client* client)  //ȸ������ 
{
	clients.push_back(client);
}
void ClientCollection::deleteClient(string ClientID) //  ȸ��Ż��
{	
	int index = findClientIndex(ClientID); 
	clients.erase(clients.begin() + (index-1));
	// �÷���Ŭ�������� clients�� ���θ����  clients�� �̸��� ���Ƽ� ���߿� �����ϰٽ��ϴ�.
}

void ClientCollection::printClient()  //�ʿ���� ���ϸ鼭 Ȯ�ο����� �ۼ��� �Լ�
{
	
	//a = clients[0]->getClientID;
	cout << clients.size() << clients[0]->getClientID() ;
}

int ClientCollection::findClientIndex(string ID)// ID�� ��ġ�ϴ� �ε��� ��ȯ
{
	int i = 0;
	for (i = 0; i < clients.size(); ++i)
	{
		if (clients[i]->getClientID() == ID)
		{
			break;
		}

	}
	return i;
}

int ClientCollection::findClientIndex()// �α��� ���� �ε��� ��ȯ
{
	int i = 0;
	for (i = 0; i < clients.size(); ++i)
	{
		if (clients[i]->getlog() == true)
		{
			return i;                  //�α������� ���̵� �÷���Ŭ�������� ã���� �ֵ��� �ε��� ��ȯ
		}

	}
	return 0;
}

