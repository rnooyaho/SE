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
bool Client::getlog_status()
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
void Client::set_log(int log_status) { //�α��� ���� �ٲٴ� �Լ�
	this->log_status = log_status;
	if (log_status == 1) {
		cout << this->clientID << "�� �α��λ��·� ����Ǿ����ϴ�." << endl; // �ּ� ���߿� ��������
	}
	else if (log_status == 0) {
		cout << this->clientID << "�� �α׾ƿ����·� ����Ǿ����ϴ�." << endl; //���߿� ����
	};
}

//collection class ����
void ClientCollection::addClient(Client* client)  //ȸ������ 
{
	clients.push_back(client);
}

void ClientCollection::deleteClient(Client* client) //  ȸ��Ż��

{	
	string ClientID = client->getClientID();
	int index = findClientIndex(ClientID); // ��ü ������ ���� �ε����� ã�� ����

	clients.erase(clients.begin()+ index);  //�α��� ���� ���̵��� index�� ã�Ƽ� �÷��� Ŭ���� ������ ����

}

void ClientCollection::printClient()  //���ϸ鼭 Ȯ�ο����� �ۼ��� ���߿� ������ �Լ�
{
	//a = clients[0]->getClientID;
	cout << "ȸ���� : " << clients.size() << endl ;
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


Client* ClientCollection::Login(string ID, string PW)// �α��� ���� �� ��ü ��ȯ
{
	int i = 0; 
	for (int i = 0; i < clients.size(); ++i)
	{
		if ((clients[i]->getClientID() == ID) && (clients[i]->getClientPW() == PW))
		{
			break;//�α������� �ε������� break
		}

	}
	return clients[i];
}
Client* ClientCollection::LoginID()// �α��� ���� �� ��ü ã�Ƽ� ��ȯ
{
	int i = 0;
	for (int i = 0; i < clients.size(); ++i)
	{
		if (clients[i]->getlog_status() == 1)
		{
			break;//�α������� �ε������� break
		}

	}
	return clients[i];
}



