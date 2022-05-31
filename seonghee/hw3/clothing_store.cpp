#include <iostream>
#include <fstream>
#include <vector>
#include "clothing_store.h"

using namespace std;

extern ifstream fin;
extern ofstream fout;

vector<Product> productDB;
Product* searchedProduct = NULL; // 검색된 상품이 있다면 Product, 아니라면 NULL
User loginUser = User(); // 예시,,

SearchProductUI::SearchProductUI(SearchProduct* controller)
{
    this->controller = controller;
    
//    Product product = Product();//
//    productDB.push_back(product);//
    
    if (fout.is_open())
    {
        fout<<"4.1. 상품 정보 검색"<<endl;
    }
    putProductName();
}

//
//Product::Product()
//{
//    this->sellerId = 1;
//    this->name = "hat";
//    this->company = "seonghee";
//    this->price = 12500;
//    this->stock = 2;
//    this->salesQuantity = 0;
//    this->averageSatisfaction = 0;
//}

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

string Product::getName()
{
    return this->name;
}

string Product::getProductDetails()
{
    string productDetails = to_string(sellerId) + " " + name + " " + company + " " + to_string(price) + " " + to_string(stock) + " " + to_string(averageSatisfaction);
    
    return productDetails;
}


void SearchProductUI::startInterface(string productDetail)
{
    fout<< ("> " + productDetail).c_str()<< endl<< endl;
}

PurchaseProduct::PurchaseProduct()
{
    PurchaseProductUI boundary = PurchaseProductUI(this);
    this->boundary = &boundary;
}

PurchaseProductUI::PurchaseProductUI(PurchaseProduct* controller)
{
    this->controller = controller;
    fout<< "4.2. 상품 구매"<< endl;
    this->purchaseProduct();
}

void PurchaseProductUI::purchaseProduct()
{
    if (searchedProduct != NULL)
    {
        bool purchaseSucceeded = this->controller->purchaseProduct();
        if(purchaseSucceeded) {
            fout<< "> " + to_string(searchedProduct->getSellerId()) + " " + searchedProduct->getName()<< endl;
            searchedProduct = NULL;
        } else {
            fout<< ""<< endl;
        }
    } else {
        fout<< ""<< endl;
    }
    fout<<endl;
}

bool PurchaseProduct::purchaseProduct()
{
    ProductCollection purchasedProductList = loginUser.getPurchasedProductList();
    int purchasedProductCount = purchasedProductList.getOwnedProductSize();
    
    for(int i = 0; i < purchasedProductCount; i++)
    {
        // 동일한 상품은 한번만 구입한다고 가정한다. <- 만족시키기 위해 현재 로그인한 유저가 지금 구매하려고 하는 상품을 구입한 내역이 있는지 확인
        // 그리고 남은 수량이 1개 이상이어야 구입할 수 있다.
        if (searchedProduct->getName() == purchasedProductList.getProductAt(i).getName() || searchedProduct->getStock() == 0)
        {
            return false; // 구매 실패
        }
    }
    searchedProduct->updateStock();
    loginUser.purchaseProduct();
    return true; // 구매 성공
}

void Product::updateStock()
{
    this->stock--;
    this->salesQuantity++;
}

void User::purchaseProduct()
{
    this->purchasedProductList.addProduct(*searchedProduct);
}

ProductCollection User::getPurchasedProductList()
{
    return this->purchasedProductList;
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
