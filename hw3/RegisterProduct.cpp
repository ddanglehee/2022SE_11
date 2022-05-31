#include "RegisterProduct.h"
extern User loginUser;

/*
	함수 이름 : RegisterProduct::addNewProduct(string name, string company, int price, int stock)
	기능	  : 새로운 상품을 생성하고, 해당 판매자에 그 상품 등록함
	전달 인자 : 유저 객체, 상품 명, 회사 명, 가격, 수량
	반환값    : 없음
    생성 일자 : 2022/5/30 7:00 PM
    작성자 :   김기선
*/
void RegisterProduct::addNewProduct(string name, string company, int price, int stock)
{
    loginUser.updateProductForSale(Product::createProduct(name, company, price, stock)); //해당 판매자의 판매 리스트에 생성된 상품 등록
    RegisterProductUI::printRegisterCompleteMessage(name, company, price, stock); //판매 완료 메세지 함수 호출
}

/*
	함수 이름 : RegisterProduct::run()
	기능	  : 상품 등록의 최초 함수, RegisterProductUI의 startInterface()를 실행함
	전달 인자 : 없음
	반환값    : 없음
    생성 일자 : 2022/5/30 7:00 PM
    작성자 :   김기선
*/
void RegisterProduct::run()
{
    RegisterProductUI::startInterface();
}


/*
	함수 이름 : RegisterProductUI::registerProduct(string name, string company, int price, int stock)
	기능	  : UI에서 상품을 등록함
	전달 인자 : 판매자 객체, 상품 명, 회사 명, 가격, 수량
	반환값    : 없음
    생성 일자 : 2022/5/30 7:00 PM
    작성자 :   김기선
*/
void RegisterProductUI::registerProduct(string name, string company, int price, int stock)
{
    RegisterProduct::addNewProduct(name, company, price, stock); //입력받은 정보들로 새로운 판매 상품 생성
}

/*
	함수 이름 : RegisterProductUI::startInterface()
	기능	  : 상품 등록을 위한 인터페이스를 출력함
	전달 인자 : 없음
	반환값    : 없음
    생성 일자 : 2022/5/30 7:00 PM
    작성자 :   김기선
*/
void RegisterProductUI::startInterface()
{
    string name, company;
    int price, stock;
    fin >> name >> company >> price >> stock;
    registerProduct(name, company, price, stock);
}

/*
	함수 이름 : RegisterProductUI::printRegisterCompleteMessage(string name, string company, int price, int stock)
	기능	  : 상품 등록 완료에 대한 메세지를 출력함
	전달 인자 : 상품 명, 회사 명, 가격, 수량
	반환값    : 없음
    생성 일자 : 2022/5/30 7:00 PM
    작성자 :   김기선
*/
void RegisterProductUI::printRegisterCompleteMessage(string name, string company, int price, int stock)
{
    fout<< "3.1.판매 의류 등록\n";
    fout<< "> " << name << " " << company << " "<< price << " " << stock << "\n\n";
}