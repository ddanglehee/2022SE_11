#ifndef _product_h_
#define _product_h_

#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <cmath>

using namespace std;

class Product
{
private:
    string sellerId;
    string name;
    string company;
    int price;
    int stock;
    int averageSatisfaction;
    int salesQuantity;
public:
    Product(string sellerId, string name, string company, int price, int stock){
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
    string getSellerId();
    int getStock();
    void updateStock();
    void updateAverageSatisfaction(int satisfaction);
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
    vector<Product> getOwnProduct();
};

#endif
