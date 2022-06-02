#include "user.h"
#include <algorithm>

using namespace std;

extern Product* searchedProduct;

bool UserCollection::checkValidation(string id, string password)
{
    // userDB에 존재하는 id, password인지 확인
}

void UserCollection::addUser(string name, string rrn, string id, string password)
{
    vector<User> user;
    user.push_back({name, rrn, id, password});

    // 이미 회원인 사람은 회원가입 불가
    if(is_permutation(userDB.begin(),userDB.end(),user.begin()))
    {
        this->userDB.insert(userDB.end(), user.begin(), user.end());
    }
}

int UserCollection::getUserDBSize()
{
    return (int)this->userDB.size();
}

vector<User> UserCollection::getUserList()
{
    return this->userDB;
}

User UserCollection::getUserAt(int index)
{
    return this->userDB.at(index);
}

void UserCollection::removeUser()
{

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

ProductCollection User::getSaleProductList()
{
    return this->productForSaleList;
};
