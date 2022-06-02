#include "user.h"
#include <algorithm>

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

    if(is_permutation(userDB.begin(),userDB.end(),user))
    {
        userDB.push_back(user);
    }
}

void User::purchaseProduct()
{
    this->purchasedProductList.addProduct(*searchedProduct);
}

<<<<<<< HEAD
=======
ProductCollection User::getSaleProductList()
{
    return this->productForSaleList;
}

>>>>>>> 075745d3f6228188202422f74118d81aa5f585ce
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

ProductCollection User::getSaleProductList()
{
    return this->productForSaleList;
};

ProductCollection User::getPurchasedProductList()
{
    return this->purchasedProductList;
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
    this->id = "";
}

/*
	함수 이름 : User::checkValidation(string id, string password)
	기능	  : 유효한 회원인지 확인하여 유효하면 true 반환
	전달 인자 : 아이디, 비밀번호
	반환값    : bool
    생성 일자 : 2022/6/2 9:00 PM
    작성자 :   이다연
*/
bool User::checkValidation(string id, string password)
{
    if(getId()==id && getPassword()==password)
        return true;
    else return false;
}
