#ifndef _product_h_
#define _product_h_

#include <iostream>
#include <vector>

using namespace std;

class Product
{
private:
    int sellerId;
    string name;
    string company;
    int price;
    int stock;
    int averageSatisfaction;
    int salesQuantity;
public:
    string getProductDetails();
    string getName();
    int getSellerId();
    int getStock();
    void updateStock();
};


class ProductCollection
{
private:
    vector<Product> ownedProduct;
public:
    void addProduct(Product product);
    int getOwnedProductSize();
    Product getProductAt(int index);
};

#endif
