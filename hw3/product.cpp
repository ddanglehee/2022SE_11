#include "product.h"

using namespace std;

string Product::getName()
{
    return this->name;
}

string Product::getProductDetails()
{
    string productDetails = to_string(sellerId) + " " + name + " " + company + " " + to_string(price) + " " + to_string(stock) + " " + to_string(averageSatisfaction);
    
    return productDetails;
}

void Product::updateStock()
{
    this->stock--;
    this->salesQuantity++;
}



int Product::getSellerId()
{
    return this->sellerId;
}

void ProductCollection::addProduct(Product product)
{
    this->ownedProduct.push_back(product);
}

Product ProductCollection::getProductAt(int index)
{
    return this->ownedProduct.at(index);
}

int ProductCollection::getOwnedProductSize()
{
    return (int)this->ownedProduct.size();
}

int Product::getStock()
{
    return this->stock;
}
