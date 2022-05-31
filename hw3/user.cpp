#include "user.h"

using namespace std;

extern Product* searchedProduct;

void User::purchaseProduct()
{
    this->purchasedProductList.addProduct(*searchedProduct);
}

ProductCollection User::getPurchasedProductList()
{
    return this->purchasedProductList;
}
