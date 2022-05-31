#include "signUp.h"

using namespace std;

extern ifstream fin;
extern ofstream fout;
extern Product* searchedProduct;
extern User loginUser;

SignUp::SignUp()
{
    SignUpUI boundary = SignUpUI(this);
    this->boundary = &boundary;
}

SignUpUI::SignUpUI(SignUp* controller)
{
    this->controller = controller;
    fout<< "1.1. 회원 가입"<< endl;
    this->purchaseProduct();
}

void SignUpUI::signUp()
{
    if (searchedProduct != NULL)
    {
        bool purchaseSucceeded = this->controller->purchaseProduct();
        if(purchaseSucceeded) {
            fout<< "> " + to_string(searchedProduct->getSellerId()) + " " + searchedProduct->getName()<< endl;
            searchedProduct = NULL;
        } else {
            fout<< ""<< endl;
        }
    } else {
        fout<< ""<< endl;
    }
    fout<<endl;
}

bool SignUp::signUp()
{
    ProductCollection purchasedProductList = loginUser.getPurchasedProductList();
    int purchasedProductCount = purchasedProductList.getOwnedProductSize();
    
    for(int i = 0; i < purchasedProductCount; i++)
    {
        // 동일한 상품은 한번만 구입한다고 가정한다. <- 만족시키기 위해 현재 로그인한 유저가 지금 구매하려고 하는 상품을 구입한 내역이 있는지 확인
        // 그리고 남은 수량이 1개 이상이어야 구입할 수 있다.
        if (searchedProduct->getName() == purchasedProductList.getProductAt(i).getName() || searchedProduct->getStock() == 0)
        {
            return false; // 구매 실패
        }
    }
    searchedProduct->updateStock();
    loginUser.purchaseProduct();
    return true; // 구매 성공
}
