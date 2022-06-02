#include "checkPurchasedProduct.h"

bool compare(Product a, Product b)
{
    return a < b;
}

CheckPurchasedProduct::CheckPurchasedProduct()
{
    CheckPurchasedProductUI boundary = CheckPurchasedProductUI(this);
    this->boundary = &boundary;
    
    vector<string> purchasedProductDetails;
    vector<Product> purchasedProductList = loginUser->getPurchasedProductList().getOwnProduct();
    sort(purchasedProductList.begin(), purchasedProductList.end(), compare);
    for(Product product : purchasedProductList)
    {
        for(Product productInDB: productDB)
        {
            if(product.getName() == productInDB.getName())
            {
                string productDetail = product.getProductDetails();
                purchasedProductDetails.push_back(productDetail);
            }
        }
    }
    boundary.startInterface(purchasedProductDetails);
}

CheckPurchasedProductUI::CheckPurchasedProductUI(CheckPurchasedProduct* controller)
{
    this->controller = controller;
    fout<< "4.3. 상품 구매 내역 조회"<< endl;
}

void CheckPurchasedProductUI::startInterface(vector<string> purchasedProductDetails)
{
    vector<string>::iterator ptr;
    for(ptr = purchasedProductDetails.begin(); ptr < purchasedProductDetails.end(); ptr++)
    {
        fout<< "> "<< *ptr<< endl;
    }
    
    fout<< endl;
}
