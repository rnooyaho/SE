#pragma once
#include <iostream>
#include "entity.h"

//Client 클래스 멤버함수 구현

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
// 여기까지 멤버 요소 접근



//setClient로 수정할까 생각중입니다.
void Client::createClient(string& name, string& SSN, string& ID, string& password)
{
	clientName = name;
	socialSecurityNumber = SSN;
	clientID = ID;
	clientPassword = password;
}
void Client::set_log(int log_status) { //로그인 상태 바꾸는 함수
	this->log_status = log_status;
	if (log_status == 1) {
		cout << this->clientID << "는 로그인상태로 변경되었습니다." << endl; // 주석 나중에 삭제예정
	}
	else if (log_status == 0) {
		cout << this->clientID << "는 로그아웃상태로 변경되었습니다." << endl; //나중에 삭제
	};
}

//collection class 구현
void ClientCollection::addClient(Client* client)  //회원가입 
{
	clients.push_back(client);
}

void ClientCollection::deleteClient(Client* client) //  회원탈퇴

{	
	string ClientID = client->getClientID();
	int index = findClientIndex(ClientID); // 객체 삭제를 위해 인덱스를 찾는 과정

	clients.erase(clients.begin()+ index);  //로그인 중인 아이디의 index를 찾아서 컬랙션 클래스 내에서 삭제

}

void ClientCollection::printClient()  //구하면서 확인용으로 작성한 나중에 삭제할 함수
{
	//a = clients[0]->getClientID;
	cout << "회원수 : " << clients.size() << endl ;
}


int ClientCollection::findClientIndex(string ID)// ID에 일치하는 인덱스 반환
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


Client* ClientCollection::Login(string ID, string PW)// 로그인 중인 고객 객체 반환
{
	int i = 0; 
	for (int i = 0; i < clients.size(); ++i)
	{
		if ((clients[i]->getClientID() == ID) && (clients[i]->getClientPW() == PW))
		{
			break;//로그인중인 인덱스에서 break
		}

	}
	return clients[i];
}
Client* ClientCollection::LoginID()// 로그인 중인 고객 객체 찾아서 반환
{
	int i = 0;
	for (int i = 0; i < clients.size(); ++i)
	{
		if (clients[i]->getlog_status() == 1)
		{
			break;//로그인중인 인덱스에서 break
		}

	}
	return clients[i];
}



