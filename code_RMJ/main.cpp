/**********************************

5.30
4.1 ~ 4.4만 input 파일에 넣어서 잘 돌아가는지 확인했어용
어제 코드는 생성자에 모든 걸 때려박았더니 너무 불안정해서 싹 고쳤습니다 ㅜㅜ
등록된 product받아오는 부분, actor받아오는 부분 등은 나중에 다른 팀원 분들 코드 따라서 수정할게요

**
4.4. 구매만족도 커뮤니케이션 다이어그램 수정해야됨
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



    ProductCollection products; //등록된 전체 상품 리스트. 나중에 코드 수정하기. 
    Product* selected = NULL; //4.1. 이후 4.2. 선택했을 때 상품 즉시 구매를 위한 포인터
    Purchaser* actor = NULL;//new Purchaser; //실험. 다시 NULL로 바꾸기. 
    
    //아래 주석은 4번대 잘 돌아가는지 보려고 만든 실험용 코드
    //Product* test = new Product; 
    //products.addProduct(test);
    //제출 전에 반드시 지우기.

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
                break;
            }
            case 2:
            {
                break;
            }
            }
        }
        case 4:
        {
            
            
            switch (menu_level_2)
            {

            case 1: // "4.1. 상품 정보 검색" 메뉴 부분 
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
                break;
            }
            case 4: // "4.4. 상품 구매만족도 평가" 메뉴 부분 
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
        //여기에 6번 복붙하면 됨
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
    fin.close();
    fout.close();
}