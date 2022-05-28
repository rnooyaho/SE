/**********************************

5.29. 첫번째 버전
파일 입출력 C++로 바꾸고 구매 부분만 구현했습니다.

등록된 전체 물건 리스트, 구매자 포인터 받아오는 방법이나 잘못 구현된 부분 등은 회의 후 수정하겠습니다.

**
4.4. 구매만족도 커뮤니케이션 다이어그램 수정해야됨
************************************/
// 헤더 선언
#include <iostream>
#include <fstream>
#include <string>

#include "UI.h"
//#include "entity.h"

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
        case 4:
        {
            Product* selected = NULL;
            Purchaser* actor = NULL;
            switch (menu_level_2)
            {

            case 1: // "4.1. 상품 정보 검색" 메뉴 부분 
            {
                vector<Product*> products; //등록된 전체 상품 리스트. 나중에 코드 수정하기. 
                Search* search = new Search(fin,products,selected,fout);
            }
            case 2: // "4.2. 상품 구매" 메뉴 부분
            {
                Purchase* purchase = new Purchase(selected,actor,fout);
            }
            case 3: // "4.3. 상품 구매 내역 조회" 메뉴 부분 
            {
                ShowShopping* showShopping = new ShowShopping(actor, fout);
            }
            case 4: // "4.4. 상품 구매만족도 평가" 메뉴 부분 
            {
                SatisfactionScore* satisfactionScore = new SatisfactionScore(fin, actor, fout);
            }
            }
        }
        case 6:
        {
            switch (menu_level_2)
            {
            case 1:   // "6.1. 종료“ 메뉴 부분
            {
                program_exit();
                is_program_exit = 1;
                break;
            }
            }
        }
        }
        return;
        }
    }
}

void program_exit()
{
    fin.close();
    fout.close();
}