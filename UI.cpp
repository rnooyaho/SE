#pragma once
#include <iostream>
#include<algorithm>
#include "UI.h"
#include <vector>
#include <algorithm>
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
	fout << "> " << name << " " << SSN << " " << ID << " " << PW << " "  << "\n";

	return newuser;
};

// 1.1 입력받은 정보를 통해 client콜랙션에 회원정보 추가
void CreateClientAccount::addNewClient(ifstream& fin, ClientCollection& ALLclients, ofstream& fout){
	Client* CCA = new Client; //회원가입할 client객체 생성
	CCA_UI = new CreateClientAccountUI;
	CCA_UI->interface(fout); //인터페이스 출력
	CCA = CCA_UI->enterClientInformation(fin,fout); //입력받은 회원정보 출력

	ALLclients.addClient(CCA);
}

// 1.2 인터페이스 출력

void DeleteClientAccountUI::interface(ofstream& fout) {
	fout << "1.2. 회원탈퇴" << endl;
}
//1.2 로그인중인 회원아이디 탈퇴 
void DeleteClientAccountUI::deleteClientAccount(ClientCollection &ALLclients, ofstream& fout) {
	
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

// 2.1 입력받은 정보를 통해 로그인 시도 
void Login::tryLogin(ifstream& fin, ClientCollection& ALLclients, ofstream& fout) 
{

	Login_UI = new LoginUI;
	Login_UI->interface(fout); //인터페이스 출력
	//ID,PW값 받기

	string* PW = Login_UI->selectLogin(fin, fout);

	cout << "Id, PW =" <<  PW[0]<< "  " << PW[1] << endl;

	// ID,PW 일치 하는 계정 log_status값 0에서 1로 변경하기 위해 호출
	Client* Login_Client = new Client;

	Login_Client = ALLclients.Login(PW[0],PW[1]); //로그인할 아이디 객체
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










