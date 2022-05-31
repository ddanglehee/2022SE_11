#include "user.h"

using namespace std;

extern Product* searchedProduct;

void User::purchaseProduct()
{
    this->purchasedProductList.addProduct(*searchedProduct);
}

ProductCollection User::getPurchasedProductList()
{
    return this->purchasedProductList;
}


/*
	함수 이름 : User::updateProductForSale(Product *product)
	기능	  : 새로운 판매 상품을 판매자의 판매 리스트에 update
	전달 인자 : 해당 상품 객체
	반환값    : 없음
    생성 일자 : 2022/5/30 7:00 PM
    작성자 :   김기선
*/
void User::updateProductForSale(Product *product)
{
    this->productForSaleList.addProduct(*product);
}

/*
	함수 이름 : User::getId()
	기능	  : 해당 판매자의 Id 반환
	전달 인자 : 없음
	반환값    : id(int)
    생성 일자 : 2022/5/30 7:00 PM
    작성자 :   김기선
*/
string User::getId()
{
    return this->Id;
}

ProductCollection User::getSaleProductList()
{
    return this->productForSaleList;
};
