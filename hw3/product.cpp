#include "product.h"
#include "user.h"

extern vector<Product> productDB;
extern User* loginUser;

using namespace std;

/*
    함수 이름 : Product::getName()
    기능      : 해당 상품의 상품명 반환
    전달 인자 : 없음
    반환값    : 상품명(string)
    생성 일자 : 2022/6/2 11:00 PM
    작성자 :   장성희

*/
string Product::getName()
{
    return this->name;
}

/*
    함수 이름 : Product::getProductDetails()
    기능      : 해당 상품의 상세 정보 반환
    전달 인자 : 없음
    반환값    : 상품 장세 정보(string)
    생성 일자 : 2022/6/2 11:00 PM
    작성자 :   장성희

*/
string Product::getProductDetails()
{
    string productDetails = sellerId + " " + name + " " + company + " " + to_string(price) + " " + to_string(stock) + " " + to_string(averageSatisfaction);
    
    return productDetails;
}

/*
    함수 이름 : Product::updateStock()
    기능      : 해당 상품의 남은 수량, 판매 수량 변경
    전달 인자 : 없음
    반환값    : 없음
    생성 일자 : 2022/6/2 11:00 PM
    작성자 :   장성희

*/
void Product::updateStock()
{
    this->stock--;
    this->salesQuantity++;
}

/*
    함수 이름 : Product::getSellerId()
    기능      : 해당 상품의 판매자 ID를 반환
    전달 인자 : 없음
    반환값    : 상품 판매자 ID(string)
    생성 일자 : 2022/6/2 11:00 PM
    작성자 :   장성희

*/
string Product::getSellerId()
{
    return this->sellerId;
}

/*
    함수 이름 : ProductCollection::addProduct(Product product)
    기능      : 새로운 상품 추가
    전달 인자 : 새로운 상품
    반환값    : 없음
    생성 일자 : 2022/6/2 11:00 PM
    작성자 :   장성희

*/
void ProductCollection::addProduct(Product product)
{
    this->ownedProduct.push_back(product);
}

/*
    함수 이름 : ProductCollection::getOwnProduct()
    기능      : ProductCollection에 있는 모든 상품 반환
    전달 인자 : 없음
    반환값    : ProductCollection에 있는 모든 상품(vector<Product>)
    생성 일자 : 2022/6/2 11:00 PM
    작성자 :   장성희

*/
vector<Product> ProductCollection::getOwnProduct()
{
    return this->ownedProduct;
}


/*
    함수 이름 : Product::getStock()
    기능      : 해당 상품의 남은 수량 반환
    전달 인자 : 없음
    반환값    : 해당 상품의 남은 수량(int)
    생성 일자 : 2022/6/2 11:00 PM
    작성자 :   장성희

*/
int Product::getStock()
{
    return this->stock;
}

/*
    함수 이름 : Product::updateAverageSatisfaction(int satisfaction)
    기능      : 해당 상품의 평균 구매만족도 갱신
    전달 인자 : 구매만족도
    반환값    : 해당 상품의 구매만족도(int)
    생성 일자 : 2022/6/2 11:00 PM
    작성자 :   장성희

*/
void Product::updateAverageSatisfaction(int satisfaction)
{
    this->averageSatisfaction += satisfaction;
    this->averageSatisfaction = round((double)this->averageSatisfaction / (double)this-> salesQuantity);
}

/*
	함수 이름 : Product::createProduct(string name, string company, int price, int stock)
	기능	  : 새로운 판매 상품 생성
	전달 인자 : 판매자 객체, 상품 명, 회사 명, 가격, 수량
	반환값    : 상품 객체 주소 반환
    생성 일자 : 2022/5/30 7:00 PM
    작성자 :   김기선

*/
Product Product::createProduct(string name, string company, int price, int stock)
{
    Product product = {loginUser->getId(), name, company, price, stock}; // 생성자를 통한 새로운 Product 객체 생성
    productDB.push_back(product);
    return product; // 같은 상품 등록을 위해서 Product 객체 주소로 반환
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
	반환값    : 상품의 평균 만족도(int)
    생성 일자 : 2022/5/30 7:00 PM
    작성자 :   김기선
*/
int Product::getAverageSatisfaction() const
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


