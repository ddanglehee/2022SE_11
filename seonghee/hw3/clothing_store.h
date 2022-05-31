#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
class SearchProductUI;
class PurchaseProductUI;

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
//    Product(); //
    string getProductDetails();
    string getName();
    int getSellerId();
    int getStock();
    void updateStock(); // !!
};

// !!
class ProductCollection
{
private:
    vector<Product> ownedProduct;
public:
    void addProduct(Product product);
    int getOwnedProductSize();
    Product getProductAt(int index);
};

// !!
class User
{
private:
    ProductCollection purchasedProductList;
public:
    void purchaseProduct();
    ProductCollection getPurchasedProductList();
};

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

// !!
class PurchaseProduct
{
private:
    PurchaseProductUI* boundary;
public:
    PurchaseProduct();
    bool purchaseProduct();
};

// !!
class PurchaseProductUI
{
private:
    PurchaseProduct* controller;
public:
    PurchaseProductUI(PurchaseProduct* controller);
    void purchaseProduct();
};

