/**********************************

5.29. ù��° ����
���� ����� C++�� �ٲٰ� ���� �κи� �����߽��ϴ�.

��ϵ� ��ü ���� ����Ʈ, ������ ������ �޾ƿ��� ����̳� �߸� ������ �κ� ���� ȸ�� �� �����ϰڽ��ϴ�.

**
4.4. ���Ÿ����� Ŀ�´����̼� ���̾�׷� �����ؾߵ�
************************************/
// ��� ����
#include <iostream>
#include <fstream>
#include <string>

#include "UI.h"
//#include "entity.h"

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
        case 4:
        {
            Product* selected = NULL;
            Purchaser* actor = NULL;
            switch (menu_level_2)
            {

            case 1: // "4.1. ��ǰ ���� �˻�" �޴� �κ� 
            {
                vector<Product*> products; //��ϵ� ��ü ��ǰ ����Ʈ. ���߿� �ڵ� �����ϱ�. 
                Search* search = new Search(fin,products,selected,fout);
            }
            case 2: // "4.2. ��ǰ ����" �޴� �κ�
            {
                Purchase* purchase = new Purchase(selected,actor,fout);
            }
            case 3: // "4.3. ��ǰ ���� ���� ��ȸ" �޴� �κ� 
            {
                ShowShopping* showShopping = new ShowShopping(actor, fout);
            }
            case 4: // "4.4. ��ǰ ���Ÿ����� ��" �޴� �κ� 
            {
                SatisfactionScore* satisfactionScore = new SatisfactionScore(fin, actor, fout);
            }
            }
        }
        case 6:
        {
            switch (menu_level_2)
            {
            case 1:   // "6.1. ���ᡰ �޴� �κ�
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