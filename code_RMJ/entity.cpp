#include "entity.h"

//������ Ŭ���� ����Լ� ����
void Purchaser::addPurchaseInformation(Product* product) //���� ��ǰ ����Ʈ �߰�
{
	purchasedProductList.push_back(product);
}
vector<Product*> Purchaser::getPurchasedProductList()
{
	return purchasedProductList;
}


//Product Ŭ���� ����Լ� ����
string Product::getProductName()
{
	return productName;
}
void Product::getProductDetails(ofstream& fout)
{
	fout << "< " << sellerID << " " << productName << " " << productCompanyName << " " << cost << " " << quantityLeft << "\n";
}
void Product::stockCorrection() //��� �� �Ǹŷ� ����
{
	quantityLeft--; //��� - 1
	quantitysold++; //�Ǹż��� + 1
}
void Product::setScore(int score)//��� ���Ÿ����� ���.
{
	float totalScore = (averageScore * (quantitysold - 1)) + float(score);
	averageScore = (totalScore / quantitysold);
}
string Product::getName()
{
	return this->productName;
}