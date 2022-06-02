#include "checkPurchasedProduct.h"

bool compare(Product a, Product b)
{
    return a < b;
}

/*
    함수 이름 : CheckPurchasedProduct::CheckPurchasedProduct()
    기능      : CheckPurchasedProduct 생성자
    전달 인자 : 없음
    반환값    : 없음
    생성 일자 : 2022/6/2 11:00 PM
    작성자 :   장성희
*/
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

/*
    함수 이름 : CheckPurchasedProductUI::CheckPurchasedProductUI(CheckPurchasedProduct* controller)
    기능      : CheckPurchasedProductUI 생성자
    전달 인자 : CheckPurchasedProduct의 참조
    반환값    : 없음
    생성 일자 : 2022/6/2 11:00 PM
    작성자 :   장성희
*/
CheckPurchasedProductUI::CheckPurchasedProductUI(CheckPurchasedProduct* controller)
{
    this->controller = controller;
    fout<< "4.3. 상품 구매 내역 조회"<< endl;
}

/*
    함수 이름 : CheckPurchasedProductUI::startInterface(vector<string> purchasedProductDetails)
    기능      : 구매한 상품들의 정보를 출력
    전달 인자 : 구매한 상품들의 정보 리스트
    반환값    : 없음
    생성 일자 : 2022/6/2 11:00 PM
    작성자 :   장성희
*/
void CheckPurchasedProductUI::startInterface(vector<string> purchasedProductDetails)
{
    vector<string>::iterator ptr;
    for(ptr = purchasedProductDetails.begin(); ptr < purchasedProductDetails.end(); ptr++)
    {
        fout<< "> "<< *ptr<< endl;
    }
    
    fout<< endl;
}
