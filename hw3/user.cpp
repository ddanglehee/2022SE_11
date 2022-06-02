#include "user.h"

using namespace std;

extern vector<User> userDB;
extern Product* searchedProduct;

/*
	함수 이름 : User::addUser(string name, string rrn, string id, string password)
	기능	  : 새로운 회원 생성
	전달 인자 : 이름, 주민번호, 아이디, 비밀번호
	반환값    : 없음
    생성 일자 : 2022/5/31 7:00 PM
    작성자 :   이다연
*/
void User::addUser(string name, string rrn, string id, string password)
{
    User user = {name, rrn, id, password};
    bool flag = true;
    for(auto inUser: userDB)
    {
        if(inUser.getRrn() == rrn)flag= false;
    }
    if(flag)userDB.push_back(user);
}

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

ProductCollection User::getSaleProductList()
{
    return this->productForSaleList;
}


/*
	함수 이름 : User::getId()
	기능	  : 해당 판매자의 Id 반환
	전달 인자 : 없음
	반환값    : id(string)
    생성 일자 : 2022/5/30 7:00 PM
    작성자 :   김기선
    Revisions : 1. 2022/6/2 11:17 PM , 김기선
                  반환 int -> string
*/
string User::getId()
{
    return this->id;
}

/*
	함수 이름 : User::getRrn()
	기능	  : 회원의 주민번호 반환
	전달 인자 : 없음
	반환값    : rrn(string)
    생성 일자 : 2022/6/3 12:00 AM
    작성자 :   이다연
*/
string User::getRrn()
{
    return this->rrn;
}

/*
	함수 이름 : User::getPassword()
	기능	  : 해당 판매자의 Password 반환
	전달 인자 : 없음
	반환값    : password(int)
    생성 일자 : 2022/6/2 9:00 PM
    작성자 :   이다연
*/
string User::getPassword()
{
    return this->password;
}

/*
	함수 이름 : User::eraseId()
	기능	  : 회원 삭제
	전달 인자 : 없음
	반환값    : 없음
    생성 일자 : 2022/6/2 8:00 PM
    작성자 :   이다연
*/
void User::eraseId()
{
    this->rrn = "";
}

/*
	함수 이름 : User::checkValidation(string id, string password)
	기능	  : 유효한 회원인지 확인하여 유효하면 true 반환
	전달 인자 : 아이디, 비밀번호
	반환값    : bool
    생성 일자 : 2022/6/2 9:00 PM
    작성자 :   이다연
*/
User* User::checkValidation(string id, string password)
{
    for(auto user:userDB)
    {
        if(user.getId()==id && user.getPassword()==password)
            return &user;
    }
    return NULL;
}
