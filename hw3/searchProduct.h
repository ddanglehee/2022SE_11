#include <iostream>
#include <fstream>
#include <vector>
#include "product.h"

using namespace std;

extern ifstream fin;
extern ofstream fout;

class SearchProductUI;

class SearchProduct
{
private:
    SearchProductUI* boundary;
    Product *findProductByNameFromDB(string productName);
public:
    SearchProduct();
    void showProduct(string productName);
};

class SearchProductUI
{
private:
    SearchProduct* controller;
public:
    SearchProductUI(SearchProduct* controller);
    void putProductName();
    void startInterface(string productDetail);
};
