#include "searchProduct.h"

extern vector<Product> productDB;
Product* searchedProduct = NULL; // 검색된 상품이 있다면 Product, 아니라면 NULL

SearchProductUI::SearchProductUI(SearchProduct* controller)
{
    this->controller = controller;
    if (fout.is_open())
    {
        fout<<"4.1. 상품 정보 검색"<<endl;
    }
    putProductName();
}

void SearchProductUI::putProductName()
{
    string name;
    fin >> name;
    this->controller->showProduct(name);
}

SearchProduct::SearchProduct()
{
    SearchProductUI boundary = SearchProductUI(this);
    this->boundary = &boundary;
}

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

Product *SearchProduct::findProductByNameFromDB(string productName)
{
    vector<Product>::iterator ptr;
    for (ptr = productDB.begin(); ptr != productDB.end(); ptr++)
    {
        if (ptr->getName() == productName)
            return &*ptr;
    }
    // 해당 이름을 가지는 상품이 없으면 NULL 리턴
    return NULL;
}

void SearchProductUI::startInterface(string productDetail)
{
    fout<< ("> " + productDetail).c_str()<< endl<< endl;
}
