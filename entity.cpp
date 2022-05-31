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
bool Client::getlog()
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
void Client::set_log(bool log_status) { //로그인 상태 바꾸는 함수
	this->log_status = log_status;

}

//collection class 구현

int ClientCollection::Login(string ID, string PW) {

	int i = 0;
	for (i = 0; i < clients.size(); i++)
	{
		if ((clients[i]->getClientID() == ID) && (clients[i] ->getClientPW ()== PW))
			//아이디 패스워드 일치시 로그인상태로 변경
		{
			clients[i]->set_log(true);
			return i; //로그인 클라이언트 인덱스값 저장
		}

	}
	// cout << "로그인에 실패했습니다" ; 나중에 예외처리 할 필요 있을시 출력인자 추가 필요.

};

void ClientCollection::addClient(Client* client)  //회원가입 
{
	clients.push_back(client);
}
void ClientCollection::deleteClient(string ClientID) //  회원탈퇴
{	
	int index = findClientIndex(ClientID); 
	clients.erase(clients.begin() + (index-1));
	// 컬래션클래스명인 clients랑 내부멤버인  clients의 이름이 같아서 나중에 수정하겟습니다.
}

void ClientCollection::printClient()  //필요없는 구하면서 확인용으로 작성한 함수
{
	
	//a = clients[0]->getClientID;
	cout << clients.size() << clients[0]->getClientID() ;
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

int ClientCollection::findClientIndex()// 로그인 중인 인덱스 반환
{
	int i = 0;
	for (i = 0; i < clients.size(); ++i)
	{
		if (clients[i]->getlog() == true)
		{
			return i;                  //로그인중인 아이디 컬랙션클래스에서 찾을수 있도록 인덱스 반환
		}

	}
	return 0;
}

