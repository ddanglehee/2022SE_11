#include "searchProduct.h"

extern vector<Product> productDB;
Product* searchedProduct = NULL; // 검색된 상품이 있다면 Product, 아니라면 NULL

/*
    함수 이름 : SearchProductUI::SearchProductUI(SearchProduct* controller)
    기능      : SearchProductUI 생성자
    전달 인자 : SearchProduct의 참조
    반환값    : 없음
    생성 일자 : 2022/6/2 11:00 PM
    작성자 :   장성희

*/
SearchProductUI::SearchProductUI(SearchProduct* controller)
{
    this->controller = controller;
    if (fout.is_open())
    {
        fout<<"4.1. 상품 정보 검색"<<endl;
    }
    putProductName();
}

/*
    함수 이름 : SearchProductUI::putProductName()
    기능      : 검색하고자 하는 상품명을 입력받음
    전달 인자 : 없음S
    반환값    : 없음
    생성 일자 : 2022/6/2 11:00 PM
    작성자 :   장성희

*/
void SearchProductUI::putProductName()
{
    string name;
    fin >> name;
    this->controller->showProduct(name);
}

/*
    함수 이름 : SearchProduct::SearchProduct()
    기능      : SearchProduct 생성자
    전달 인자 : 없음
    반환값    : 없음
    생성 일자 : 2022/6/2 11:00 PM
    작성자 :   장성희

*/
SearchProduct::SearchProduct()
{
    SearchProductUI boundary = SearchProductUI(this);
    this->boundary = &boundary;
}

/*
    함수 이름 : SearchProduct::showProduct(string productName)
    기능      : 검색 결과(검색한 상품에 대한 상세 정보)를 보여주기 위해 상품 정보를 불러오고 화면에 정보 보냄
    전달 인자 : 검색한 상품명(string)
    반환값    : 없음
    생성 일자 : 2022/6/2 11:00 PM
    작성자 :   장성희

*/
void SearchProduct::showProduct(string productName)
{
    searchedProduct = findProductByNameFromDB(productName);
    if (searchedProduct != NULL)
    {
        string productDetail = searchedProduct->getProductDetails();
        this->boundary->startInterface(productDetail);
    } else {
        this->boundary->startInterface("");
    }
}

/*
    함수 이름 : SearchProduct::findProductByNameFromDB(string productName)
    기능      : 검색어로 입력된 상품명에 대한 상품을 DB에서 찾음
    전달 인자 : 검색한 상품명(string)
    반환값    : 검색한 상품의 참조(Product*)
    생성 일자 : 2022/6/2 11:00 PM
    작성자 :   장성희

*/
Product *SearchProduct::findProductByNameFromDB(string productName)
{
    for (auto& ptr: productDB)
    {
        if (ptr.getName() == productName)
            return &ptr;
    }
    // 해당 이름을 가지는 상품이 없으면 NULL 리턴
    return NULL;
}

/*
    함수 이름 : SearchProductUI::startInterface(string productDetail)
    기능      : 검색 결과를 출력함
    전달 인자 : 상품의 상세정보(string)
    반환값    : 없음
    생성 일자 : 2022/6/2 11:00 PM
    작성자 :   장성희

*/
void SearchProductUI::startInterface(string productDetail)
{
    fout<< ("> " + productDetail).c_str()<< endl<< endl;
}
