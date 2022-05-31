#include <iostream>
#include <fstream>
#include <vector>
#include "product.h"
#include "user.h"


using namespace std;

class PurchaseProductUI;

class PurchaseProduct
{
private:
    PurchaseProductUI* boundary;
public:
    PurchaseProduct();
    bool purchaseProduct();
};

class PurchaseProductUI
{
private:
    PurchaseProduct* controller;
public:
    PurchaseProductUI(PurchaseProduct* controller);
    void purchaseProduct();
};


