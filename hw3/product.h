#ifndef _product_h_
#define _product_h_

#include <iostream>
#include <vector>
#include <string>
#include <tuple>

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
    Product(int sellerId, string name, string company, int price, int stock){
        this->sellerId = sellerId;
        this->name = name;
        this->company = company;
        this->price = price;
        this->stock = stock;
        this->salesQuantity = 0;
        this->averageSatisfaction = 0;
    }
    static Product createProduct(string name, string company, int price, int stock);
    static tuple<string, string, int, int> getSaleProductDetails(Product product);
    string getProductDetails();
    string getName();
    string getCompany() const;
    int getSellerId();
    int getStock();
    void updateStock();
    int getPrice() const;
    int getSalesQuantity() const;
    int getTotalSales() const;
    double getAverageSatisfaction() const;
};


class ProductCollection
{
private:
    vector<Product> ownedProduct;
public:
    void addProduct(Product product);
    int getOwnedProductSize();
    vector<Product> getOwnProduct();
    Product getProductAt(int index);
};

#endif
