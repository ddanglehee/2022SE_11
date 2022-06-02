#include <iostream>
#include <fstream>
#include <vector>
#include "product.h"
using namespace std;

#ifndef _USER_H_
#define _USER_H_

class User
{
private:
    string name;
    string rrn;
    string password;
    string id;
    ProductCollection productForSaleList;
    ProductCollection purchasedProductList;
public:
    User(string name, string rrn, string id, string password){
        this->name = name;
        this->rrn = rrn;
        this->id = id;
        this->password = password;
    }
    void addUser(string name, string rrn, string id, string password);
    void purchaseProduct();
    void updateProductForSale(Product *product);
    ProductCollection getSaleProductList();
    ProductCollection getPurchasedProductList();
    string getId();
    string getPassword();
    void eraseId();
    bool checkValidation(string id, string password);
};

#endif
