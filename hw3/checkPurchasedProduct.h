#ifndef checkPurchasedProduct_h
#define checkPurchasedProduct_h
#include <iostream>
#include <fstream>
#include <vector>
#include "user.h"

using namespace std;

extern ifstream fin;
extern ofstream fout;
extern User* loginUser;
class CheckPurchasedProduct;

class CheckPurchasedProductUI
{
private:
    CheckPurchasedProduct* controller;
public:
    CheckPurchasedProductUI(CheckPurchasedProduct* controller);
    void startInterface(vector<string> purchasedProductDetails);
};

class CheckPurchasedProduct
{
private:
    CheckPurchasedProductUI* boundary;
public:
    CheckPurchasedProduct();
};

#endif /* checkPurchasedProduct_h */
