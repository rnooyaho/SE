/**********************************

5.30
4.1 ~ 4.4�� input ���Ͽ� �־ �� ���ư����� Ȯ���߾��
���� �ڵ�� �����ڿ� ��� �� �����ھҴ��� �ʹ� �Ҿ����ؼ� �� ���ƽ��ϴ� �̤�
��ϵ� product�޾ƿ��� �κ�, actor�޾ƿ��� �κ� ���� ���߿� �ٸ� ���� �е� �ڵ� ���� �����ҰԿ�

**
4.4. ���Ÿ����� Ŀ�´����̼� ���̾�׷� �����ؾߵ�
************************************/
#pragma once
// ��� ����
#include <iostream>
#include <fstream>
#include <string>

#include "UI.h"
#include "entity.h"

// ��� ����
//#define MAX_STRING 32
#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"
using namespace std;


// �Լ� ����
void doTask();
void program_exit();


// ���� ������� ���� ���� ������ ���� ����.
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
    // �޴� �Ľ��� ���� level ������ ���� ����
    int menu_level_1 = 0, menu_level_2 = 0;
    int is_program_exit = 0;



    ProductCollection products; //��ϵ� ��ü ��ǰ ����Ʈ. ���߿� �ڵ� �����ϱ�. 
    Product* selected = NULL; //4.1. ���� 4.2. �������� �� ��ǰ ��� ���Ÿ� ���� ������
    Purchaser* actor = NULL;//new Purchaser; //����. �ٽ� NULL�� �ٲٱ�. 
    
    //�Ʒ� �ּ��� 4���� �� ���ư����� ������ ���� ����� �ڵ�
    //Product* test = new Product; 
    //products.addProduct(test);
    //���� ���� �ݵ�� �����.

    while (!is_program_exit)
    {

        // �Է����Ͽ��� �޴� ���� 2���� �б�
        //fscanf(in_fp, "%d %d ", &menu_level_1, &menu_level_2);
        fin >> menu_level_1 >> menu_level_2;

        // �޴� ���� �� �ش� ���� ����
        switch (menu_level_1)
        {
        case 1:
        {
            switch (menu_level_2)
            {
            case 1:   // "1.1. ȸ�����ԡ� �޴� �κ�
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

            case 1: // "4.1. ��ǰ ���� �˻�" �޴� �κ� 
            {
                //cout << "4.1." << endl;
                Search* search = new Search;
                selected = search->run(fin, products, selected, fout);
                delete search;
                fout << "\n";
                break;
            }
            case 2: // "4.2. ��ǰ ����" �޴� �κ�
            {
                //cout << "4.2." << endl;
                Purchase* purchase = new Purchase;
                actor = purchase->run(selected, actor, fout);
                fout << "\n";
                break;
            }
            case 3: // "4.3. ��ǰ ���� ���� ��ȸ" �޴� �κ� 
            {
                //cout << "4.3." << endl;
                ShowShopping* showShopping = new ShowShopping;
                showShopping->run(actor, fout);
                break;
            }
            case 4: // "4.4. ��ǰ ���Ÿ����� ��" �޴� �κ� 
            {
                //cout << "4.4." << endl;
                SatisfactionScore* satisfactionScore = new SatisfactionScore;
                satisfactionScore->run(fin, actor, fout);
                fout << "\n";
                break;
            }
            }
            break; //�̰� �����ϱ� 6������ �Ѿ���� �Ф�
        }
        //���⿡ 6�� �����ϸ� ��
        case 6:
        {
            switch (menu_level_2)
            {
            case 1:   // "6.1. ���ᡰ �޴� �κ�
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