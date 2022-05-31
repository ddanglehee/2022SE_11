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
    int Id;
    ProductCollection productForSaleList;
    ProductCollection purchasedProductList;
public:
    void purchaseProduct();
    void updateProductForSale(Product *product);
    ProductCollection getSaleProductList();
    ProductCollection getPurchasedProductList();
    int getId();
};

#endif
