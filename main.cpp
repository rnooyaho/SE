/*

 회원 가입 단계 테스트 완료하였고 (컬랙션클래스에 추가)

로그인 ,로그아웃 부분은 일단 구현 해놓고 테스트데이터 돌리진 못했습니다.
(회의전에 시간 또 최대한  내보겠습니다.)

회의를 통해서 어떤식으로 로그인 상태를 이용할지 고민해보고 수정진행할 것 같습니다!

예외처리도 어느정도까지 할지 같이고민해서 수정방향 잡으면 좋을것같아요




//메모
컬랙션클래스 변수 프라이빗으로 수정하기
회원탍퇴 테스트케이스 돌리기
코드 전체적으로 깔끔하게 수정하기
*/
#pragma once
// 헤더 선언
#include <iostream>
#include <fstream>
#include <string>

#include "UI.h"
#include "entity.h"

// 상수 선언
#define MAX_STRING 32
#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"
using namespace std;


// 함수 선언
void doTask();
void program_exit();


// 파일 입출력을 위한 파일 포인터 변수 선언.
ifstream fin(INPUT_FILE_NAME);
ofstream fout(OUTPUT_FILE_NAME);
//ofstream fout;
int main()
{
    doTask();
    return 0;
}


void doTask()
{
    // 메뉴 파싱을 위한 level 구분을 위한 변수
    int menu_level_1 = 0, menu_level_2 = 0;
    int is_program_exit = 0;

    ClientCollection Allclients;
    ProductCollection products; //등록된 전체 상품 리스트. 나중에 코드 수정하기. 
    Product* selected = NULL; //4.1. 이후 4.2. 선택했을 때 상품 즉시 구매를 위한 포인터
    Purchaser* actor = NULL;//new Purchaser; //실험. 다시 NULL로 바꾸기. 



    while (!is_program_exit)
    {

        // 입력파일에서 메뉴 숫자 2개를 읽기
        //fscanf(in_fp, "%d %d ", &menu_level_1, &menu_level_2);
        fin >> menu_level_1 >> menu_level_2;

        // 메뉴 구분 및 해당 연산 수행
        switch (menu_level_1)
        {
        case 1:
        {
            switch (menu_level_2)
            {
            case 1:   // "1.1. 회원가입“ 메뉴 부분
            {
                CreateClientAccount* client = new CreateClientAccount;
                client->addNewClient(fin, Allclients, fout);
                
                Allclients.printClient(); // 회원수 출력
                break;
            }
            case 2:
            {
                DeleteClientAccount *dclient = new DeleteClientAccount;
                dclient->deleteClient(fin, Allclients, fout);

                Allclients.printClient(); // 회원수 출력
                break;
            }
            }
            break;
        }
        case 2:
        {


            switch (menu_level_2)
            {
            case 1: 
            {
                Login* log = new Login;
                log->tryLogin(fin, Allclients, fout); //로그인

                break;
            }
            case 2:
            {
                Logout* log_out = new Logout;
                log_out->tryLogout(Allclients, fout); //로그아웃
                break;
            }
            }
            break;
        }
        case 4:
        {


            switch (menu_level_2)
            {

            case 1: // "4.1. 상품 정보 검색" 메뉴 부분 input : 4 1 hat
            {
                //cout << "4.1." << endl;
                Search* search = new Search;
                selected = search->run(fin, products, selected, fout);
                delete search;
                fout << "\n";
                break;
            }
            case 2: // "4.2. 상품 구매" 메뉴 부분 
            {
                //cout << "4.2." << endl;
                Purchase* purchase = new Purchase;
                actor = purchase->run(selected, actor, fout);
                fout << "\n";
                break;
            }
            case 3: // "4.3. 상품 구매 내역 조회" 메뉴 부분 
            {
                //cout << "4.3." << endl;
                ShowShopping* showShopping = new ShowShopping;
                showShopping->run(actor, fout);
                fout << "\n";
                break;
            }
            case 4: // "4.4. 상품 구매만족도 평가" 메뉴 부분 input : 4 4 hat 3
            {
                //cout << "4.4." << endl;
                SatisfactionScore* satisfactionScore = new SatisfactionScore;
                satisfactionScore->run(fin, actor, fout);
                fout << "\n";
                break;
            }
            }
            break; //이거 없으니까 6번으로 넘어가버림 ㅠㅠ
        }
        case 6:
        {
            switch (menu_level_2)
            {
            case 1:   // "6.1. 종료“ 메뉴 부분
            {
                program_exit();
                is_program_exit = 1;
                cout << "종료";
                //break;
                return;
            }
            }
            break;
        }
        } //switch 1        
    }
}

/*
void join()
{
    char user_type[MAX_STRING], name[MAX_STRING], SSN [MAX_STRING],
        address[MAX_STRING], ID[MAX_STRING], password[MAX_STRING];

    // 입력 형식 : 이름, 주민번호, ID, Password를 파일로부터 읽음
    fscanf(in_fp, "%s %s %s %s", name, SSN, ID, password);

    // 해당 기능 수행  
   

        // 출력 형식
        fprintf(out_fp, "1.1. 회원가입\n");
    fprintf(out_fp, "%s %s %s %s\n", name, SSN, ID, password);
}
*/

void program_exit()
{
    fin.close();
    fout.close();
}