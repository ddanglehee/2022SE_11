#include "InquireProductsForSale.h"
extern User* loginUser;

/*
	함수 이름 : InquireProductsForSale::run(User *user)
	기능	  :   판매 상품 리스트 요청 시 최초 동작, 해당 판매자의 모든 판매 상품 리스트 정보를 반환
	전달 인자 : 없음
	반환값    : 없음
    생성 일자 : 2022/5/30 7:00 PM
    작성자 :   김기선
*/
void InquireProductsForSale::run()
{
    vector<tuple<string, string, int, int>> ret;
    for(Product product : loginUser->getSaleProductList().getOwnProduct()){
        ret.push_back(Product::getSaleProductDetails(product));
    }
    InquireProductForSaleUI::startInterface(ret);
}

/*
	함수 이름 : InquireProductForSaleUI::startInterface(vector<tuple<string, string, int, int> > productsForSale)
	기능	  :   판매 상품 리스트 출력
	전달 인자 : vector<tuple<>> 형태로, 판매 상품 등록한 모든 상품들 정보, 상품 명(string), 회사 명(string), 가격(int), 수량(int)
	반환값    : 없음
    생성 일자 : 2022/5/30 7:00 PM
    작성자 :   김기선
*/
void InquireProductForSaleUI::startInterface(vector<tuple<string, string, int, int> > productsForSale)
{
    fout << "3.2. 등록 상품 조회\n";
    for(auto [name, company, price, stock] : productsForSale){
        fout << "> " << name << " " << company << " " << price << " " << stock << "\n";
    }
    fout<< endl;
}
