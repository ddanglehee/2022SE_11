#include <iostream>
#include <fstream>
#include <vector>
#include "product.h"

using namespace std;

class User
{
private:
    ProductCollection purchasedProductList;
public:
    void purchaseProduct();
    ProductCollection getPurchasedProductList();
};
