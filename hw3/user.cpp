#include "user.h"

using namespace std;

extern Product* searchedProduct;

/*
    함수 이름 : User::purchaseProduct()
    기능      : 사용자가 상품 구매
    전달 인자 : 없음
    반환값    : 없음
    생성 일자 : 2022/6/2 11:00 PM
    작성자 :   장성희

*/
void User::purchaseProduct()
{
    this->purchasedProductList.addProduct(*searchedProduct);
}

/*
    함수 이름 : User::getPurchasedProductList()
    기능      : 사용자가 구매한 상품 리스트를 반환
    전달 인자 : 없음
    반환값    : 사용자가 구매한 상품 리스트(ProductCollection)
    생성 일자 : 2022/6/2 11:00 PM
    작성자 :   장성희

*/
ProductCollection User::getPurchasedProductList()
{
    return (this->purchasedProductList);
}

ProductCollection User::getSaleProductList()
{
    return (this->productForSaleList);
}

/*
	함수 이름 : User::updateProductForSale(Product* product)
	기능	  : 새로운 판매 상품을 판매자의 판매 리스트에 update
	전달 인자 : 해당 상품 객체
	반환값    : 없음
    생성 일자 : 2022/5/30 7:00 PM
    작성자 :   김기선
*/
void User::updateProductForSale(Product* product)
{
    this->productForSaleList.addProduct(*product);
}

/*
	함수 이름 : User::getId()
	기능	  : 해당 판매자의 Id 반환
	전달 인자 : 없음
	반환값    : id(string)
    생성 일자 : 2022/5/30 7:00 PM
    작성자 :   김기선
    Revsions : 1. 2022/6/2 11:17 PM , 김기선
                  반환 int -> string
*/
string User::getId()
{
    return this->Id;
}
