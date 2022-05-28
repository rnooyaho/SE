#include "entity.h"

//구매자 클래스 멤버함수 구현
void Purchaser::addPurchaseInformation(Product* product) //구매 상품 리스트 추가
{
	purchasedProductList.push_back(product);
}
vector<Product*> Purchaser::getPurchasedProductList()
{
	return purchasedProductList;
}


//Product 클래스 멤버함수 구현
string Product::getProductName()
{
	return productName;
}
void Product::getProductDetails(ofstream& fout)
{
	fout << "< " << sellerID << " " << productName << " " << productCompanyName << " " << cost << " " << quantityLeft << "\n";
}
void Product::stockCorrection() //재고 및 판매량 수정
{
	quantityLeft--; //재고 - 1
	quantitysold++; //판매수량 + 1
}
void Product::setScore(int score)//평균 구매만족도 계산.
{
	float totalScore = (averageScore * (quantitysold - 1)) + float(score);
	averageScore = (totalScore / quantitysold);
}
string Product::getName()
{
	return this->productName;
}