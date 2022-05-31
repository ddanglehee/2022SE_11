#include "product.h"
#include "user.h"

extern vector<Product> productDB;
extern User loginUser;

using namespace std;

string Product::getName()
{
    return this->name;
}

string Product::getProductDetails()
{
    string productDetails = to_string(sellerId) + " " + name + " " + company + " " + to_string(price) + " " + to_string(stock) + " " + to_string(averageSatisfaction);
    
    return productDetails;
}

void Product::updateStock()
{
    this->stock--;
    this->salesQuantity++;
}



int Product::getSellerId()
{
    return this->sellerId;
}

void ProductCollection::addProduct(Product product)
{
    this->ownedProduct.push_back(product);
}

Product ProductCollection::getProductAt(int index)
{
    return this->ownedProduct.at(index);
}

int ProductCollection::getOwnedProductSize()
{
    return (int)this->ownedProduct.size();
}

int Product::getStock()
{
    return this->stock;
}

/*
	함수 이름 : Product::createProduct(string name, string company, int price, int stock)
	기능	  : 새로운 판매 상품 생성
	전달 인자 : 판매자 객체, 상품 명, 회사 명, 가격, 수량
	반환값    : 상품 객체 주소 반환
    생성 일자 : 2022/5/30 7:00 PM
    작성자 :   김기선

*/
Product *Product::createProduct(string name, string company, int price, int stock)
{
    Product product = {loginUser.getId(), name, company, price, stock}; // 생성자를 통한 새로운 Product 객체 생성
    productDB.push_back(product);
    return &product; // 같은 상품 등록을 위해서 Product 객체 주소로 반환
}

vector<Product> ProductCollection::getOwnProduct()
{
    return this->ownedProduct;
}

/*
	함수 이름 : Product::getSaleProductDetails(Product *product)
	기능	  : 해당 상품의 정보 반환
	전달 인자 : 상품 객체
	반환값    : 상품 명(string), 회사 명(string), 가격(int), 수량(int) , tuple로 반환
    생성 일자 : 2022/5/30 7:00 PM
    작성자 :   김기선


*/
tuple<string, string, int, int> Product::getSaleProductDetails(Product product)
{
    return {product.getName(), product.getCompany(), product.getPrice(), product.getStock()}; //상품 정보들 반환
}



/*
	함수 이름 : Product::getPrice()
	기능	  : 해당 상품의 가격 반환
	전달 인자 : 없음
	반환값    : 상품 가격(int)
    생성 일자 : 2022/5/30 7:00 PM
    작성자 :   김기선

*/
int Product::getPrice() const
{
    return this->price;
}

/*
	함수 이름 : Product::getSalesQuantity()
	기능	  : 해당 상품의 판매 수량 반환
	전달 인자 : 없음
	반환값    : 상품 판매 수량(int)
    생성 일자 : 2022/5/30 7:00 PM
    작성자 :   김기선

*/
int Product::getSalesQuantity() const
{
    return this->salesQuantity;
}

/*
	함수 이름 : Product::getTotalSales()
	기능	  : 해당 상품의 총 판매 금액 반환
	전달 인자 : 없음
	반환값    : 상품의 총 판매 금액(int)
    생성 일자 : 2022/5/30 7:00 PM
    작성자 :   김기선

*/
int Product::getTotalSales() const
{
    return (this->getPrice() * this->getSalesQuantity());
}

/*
	함수 이름 : Product::getAverageSatisfaction()
	기능	  : 해당 상품의 평균 만족도 반환
	전달 인자 : 없음
	반환값    : 상품의 평균 만족도(double)
    생성 일자 : 2022/5/30 7:00 PM
    작성자 :   김기선
*/
double Product::getAverageSatisfaction() const
{
    return this->averageSatisfaction;
}

/*
	함수 이름 : Product::getCompany()
	기능	  : 해당 상품의 회사 명 반환
	전달 인자 : 없음
	반환값    : 상품 회사 명(string)
    생성 일자 : 2022/5/30 7:00 PM
    작성자 :   김기선
*/
string Product::getCompany() const
{
    return this->company;
}


