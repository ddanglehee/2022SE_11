#include "user.h"
#include <algorithm>

using namespace std;

extern vector<User> userDB;
extern Product* searchedProduct;

void User::addUser(string name, string rrn, string id, string password)
{
    User user = {name, rrn, id, password};

    // 이미 회원인 사람은 회원가입 불가
    if(is_permutation(userDB.begin(),userDB.end(),user))
    {
        userDB.push_back(user);
    }
}

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
    return this->id;
}

void User::eraseId()
{
    this->id = "";
}

bool User::checkValidation()
{
    return true;
}

ProductCollection User::getSaleProductList()
{
    return this->productForSaleList;
};
