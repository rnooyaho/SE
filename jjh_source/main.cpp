#pragma once

#include <iostream>
#include <string>
#include <fstream>
#include "UI.h"
#include "entity.h"

#define MAX_STRING 32
#define INPUT_FILE_NAME "intput.txt"
#define OUTPUT_FILE_NAME "output.txt"
using namespace std;

void doTask();
void program_exit();

ProductCollection sellerproducts;
Client* curClient = NULL;//���� �α����� ID

ifstream fin(INPUT_FILE_NAME);
ofstream fout(OUTPUT_FILE_NAME);

int main()
{
	doTask();

	return 0;

}

void doTask()
{
	int menu_level_1 = 0, menu_level_2 = 0;
	int is_program_exit = 0;

	while (!is_program_exit)
	{
		fin >> menu_level_1 >> menu_level_2;

		switch (menu_level_1)
		{
		case 1:
		{
			switch (menu_level_2)
			{
			case 1:
			{
				break;
			}
			case 2:
			{
				break;
			}
			}
		}
		case 3:
		{
			switch (menu_level_2)
			{
			case 1://3.1 �Ǹ� �Ƿ� ���
			{
				AddProduct* product = new AddProduct(sellerproducts, curClient, fin, fout);
				product->getAddProductUI()->enterProductInformation(fin, fout, product);
				
				break;
			}
			case 2://3.2 ��� ��ǰ ��ȸ
			{
				SearchProductForSale* searchProductForSale = new SearchProductForSale(sellerproducts, curClient, fin, fout);
				searchProductForSale->getSearchProductForSaleUI()->selectProductForSale(searchProductForSale);
				
				break;
			}
			case 3://3.3 �Ǹ� �Ϸ� ��ǰ ��ȸ
			{

				break;
			}
			}
		}
		case 5://5.1 �Ǹ� ��ǰ ���
		{
			switch (menu_level_2)
			{
			case 1:
			{

				break;
			}
			}
		}
		case 6:
		{
			switch (menu_level_2)
			{
			case 1:
			{
				program_exit();
				is_program_exit = 1;
				break;
			}
			}
			break;
		}
		}
	}
}

void program_exit()
{
	fout << "6.1. ����" << endl;
	fin.close();
	fout.close();
}