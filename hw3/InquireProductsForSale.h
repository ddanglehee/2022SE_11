#include"user.h"
#include"product.h"
#include<fstream>
#include<tuple>

extern ifstream fin;
extern ofstream fout;

class InquireProductForSaleUI;

class InquireProductsForSale {
private:
    InquireProductForSaleUI* boundary;
public:
    static void run();
};


class InquireProductForSaleUI {
private:
    InquireProductsForSale* controller;
public:
    static void startInterface(vector<tuple<string, string, int, int> > productsForSale);
};


