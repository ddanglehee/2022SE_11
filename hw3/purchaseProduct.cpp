#include "purchaseProduct.h"

using namespace std;

extern ifstream fin;
extern ofstream fout;
extern Product* searchedProduct;
extern User* loginUser;

/*
    함수 이름 : PurchaseProduct::PurchaseProduct()
    기능      : PurchaseProduct 생성자
    전달 인자 : 없음
    반환값    : 없음
    생성 일자 : 2022/6/2 11:00 PM
    작성자 :   장성희
*/
PurchaseProduct::PurchaseProduct()
{
    PurchaseProductUI boundary = PurchaseProductUI(this);
    this->boundary = &boundary;
}

/*
    함수 이름 : PurchaseProductUI::PurchaseProductUI(PurchaseProduct* controller)
    기능      : PurchaseProductUI 생성자
    전달 인자 : PurchaseProduct의 참조
    반환값    : 없음
    생성 일자 : 2022/6/2 11:00 PM
    작성자 :   장성희
*/
PurchaseProductUI::PurchaseProductUI(PurchaseProduct* controller)
{
    this->controller = controller;
    fout<< "4.2. 상품 구매"<< endl;
    this->purchaseProduct();
}

/*
    함수 이름 : PurchaseProductUI::purchaseProduct()
    기능      : 상품을 구매하고 상품의 판매자 id와 상품명을 출력
    전달 인자 : 없음
    반환값    : 없음
    생성 일자 : 2022/6/2 11:00 PM
    작성자 :   장성희
*/
void PurchaseProductUI::purchaseProduct()
{
    if (searchedProduct != NULL)
    {
        bool purchaseSucceeded = this->controller->purchaseProduct();
        if(purchaseSucceeded) {
            fout<< "> " + searchedProduct->getSellerId() + " " + searchedProduct->getName()<< endl;
            searchedProduct = NULL;
        } else {
            fout<< "";
        }
    } else {
        fout<< "";
    }
    fout<<endl;
}

/*
    함수 이름 : PurchaseProduct::purchaseProduct()
    기능      : 상품을 구매함
    전달 인자 : 없음
    반환값    : 상품 구매 성공 여부(bool)
    생성 일자 : 2022/6/2 11:00 PM
    작성자 :   장성희
*/
bool PurchaseProduct::purchaseProduct()
{
    for(Product purchasedProduct : loginUser->getPurchasedProductList().getOwnProduct())
    {
        // 동일한 상품은 한번만 구입한다고 가정한다. <- 만족시키기 위해 현재 로그인한 유저가 지금 구매하려고 하는 상품을 구입한 내역이 있는지 확인
        // 그리고 남은 수량이 1개 이상이어야 구입할 수 있다.
        if (searchedProduct->getName() == purchasedProduct.getName() || searchedProduct->getStock() == 0)
        {
            return false; // 구매 실패
        }
    }
    searchedProduct->updateStock();
    loginUser->purchaseProduct();
    return true; // 구매 성공
}
