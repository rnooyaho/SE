/**********************************

5.30
4.1 ~ 4.4만 input 파일에 넣어서 잘 돌아가는지 확인했어용
등록된 product받아오는 부분 등은 나중에 다른 팀원 분들이 하신 거 보고 수정할게요
다른 부분 수정은 화요일 회의 이후에 하겠습니다.

5.30. (2)
파일 입출력이 boundary class에서만 일어나도록 수정했습니다.
돌아가는 것도 확인했슴다ㅎㅎ

5.30. (3)
Purchaser클래스를 Client 클래스로 합쳤습니다.

*memo*
* 다이어그램 수정하기
4.4. 구매만족도 커뮤니케이션 다이어그램 수정해야됨

4.1. 검색 할 땐 재고 0인 거 출력 안 하도록 해야되나..?
4.4. 평균 만족도는 소수점 첫째자리에서 반올림해서 정수.

************************************/
#pragma once
// 헤더 선언
#include <iostream>
#include <fstream>
#include <string>

#include "UI.h"
#include "entity.h"

// 상수 선언
//#define MAX_STRING 32
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
    ProductCollection totalProducts; //등록된 전체 상품 리스트.
    Client* actor = NULL; //현재 로그인한 사람. 
    Product* selected = NULL; //4.1. 이후 4.2. 선택했을 때 상품 즉시 구매를 위한 포인터


    //아래 주석은 4번대 잘 돌아가는지 보려고 만든 실험용 코드
    //Product* test = new Product;
    //products.addProduct(test);
    //Client* actor = new Client;
    //제출 전에 반드시 지우기.

    while (!is_program_exit)
    {
        // 입력파일에서 메뉴 숫자 2개를 읽기
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
                fout << "\n";

                Allclients.printClient(); // 회원수 출력
                break;
            }
            case 2:
            {
                DeleteClientAccount* dclient = new DeleteClientAccount;
                dclient->deleteClient(fin, Allclients, fout);
                fout << "\n";

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

                actor = Allclients.LoginID(); //로그인된 액터 받아오기. 3,4에 꼭 필요
                fout << "\n";
                break;
            }
            case 2:
            {
                Logout* log_out = new Logout;
                log_out->tryLogout(Allclients, fout); //로그아웃

                fout << "\n";
                actor = NULL; //로그아웃된 액터 지우기. 
                break;
            }
            }
            break;
        }
        case 3:
        {
            switch (menu_level_2)
            {
            case 1://3.1 판매 의류 등록
            {
                AddProduct* addProduct = new AddProduct;
                addProduct->run(fin, actor, totalProducts, fout);
                fout << "\n";
                break;
            }
            case 2://3.2 등록 상품 조회
            {
                ProductForSale* productForSale = new ProductForSale;
                productForSale->run(actor, fout);
                fout << "\n";
                break;
            }
            case 3://3.3 판매 완료 상품 조회
            {
                ListSoldProduct* listSoldProduct = new ListSoldProduct;
                listSoldProduct->run(actor, fout);
                fout << "\n";
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
                cout << actor->getClientID() << endl;//지우기.
                Search* search = new Search;
                selected = search->run(fin, totalProducts, selected, fout);
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
            break; 
        }
        case 5:
        {
            switch (menu_level_2)
            {
            case 1: //5.1 판매 상품 통계
            {
                //cout << "5.1." << endl;
                ShowStatistic* showStatistic = new ShowStatistic;
                showStatistic->run(actor, fout);
                fout << "\n";
                break;
            }
            }
            break;
        }
        case 6:
        {
            switch (menu_level_2)
            {
            case 1:   // "6.1. 종료“ 메뉴 부분
            {
                program_exit();
                is_program_exit = 1;
                //break;
                return;
            }
            }
            break;
        }
        } //switch 1        
    }
}

void program_exit()
{
    fout << "6.1.종료\n";
    fout << "\n";
    fin.close();
    fout.close();
}