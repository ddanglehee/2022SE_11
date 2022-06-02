#include "checkPurchasedProduct.h"

CheckPurchasedProduct::CheckPurchasedProduct()
{
    CheckPurchasedProductUI boundary = CheckPurchasedProductUI(this);
    this->boundary = &boundary;
    
    vector<string> purchasedProductDetails;
    for(Product product : loginUser->getPurchasedProductList().getOwnProduct())
    {
        string productDetail = product.getProductDetails();
        purchasedProductDetails.push_back(productDetail);
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
