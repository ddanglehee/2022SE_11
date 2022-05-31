#include "InquireSoldOutProduct.h"
extern User loginUser;

/*
	함수 이름 : InquireSoldOutProductUI::startInterface(vector<tuple<string, string, int, int> > productsSoldOut)
	기능	  : 판매 완료 상품 조회 요청 시 최초 동작, 판매자의 판매 상품 리스트를 조회해서 수량이 0인 상품들의 정보들을 InquireSoldOutProductUI의 startInterface에 전달
	전달 인자 : 판매자 객체
	반환값    : 없음
    생성 일자 : 2022/5/30 7:00 PM
    작성자 :   김기선
*/
void InquireSoldOutProduct::run()
{
    vector<tuple<string, string, int, int>> ret;
    for(Product product : loginUser.getSaleProductList().getOwnProduct()){
        if(product.getStock() == 0){ //판매자의 상품 리스트에서 수량이 0인, 즉 판매 완료된 경우 체크
            ret.push_back(Product::getSaleProductDetails(product)); // 판매 완료 상품 정보 ret에 저장
        }
    }
    InquireSoldOutProductUI::startInterface(ret);
}


/*
	함수 이름 : InquireSoldOutProductUI::startInterface(vector<tuple<string, string, int, int> > productsSoldOut)
	기능	  : 사용자에게 판매 완료된 상품 정보 출력
	전달 인자 : tuple로 상품 명(string), 회사 명(string), 가격(int), 수량(int)
	반환값    : 없음
    생성 일자 : 2022/5/30 7:00 PM
    작성자 :   김기선
*/
void InquireSoldOutProductUI::startInterface(vector<tuple<string, string, int, int> > productsSoldOut)
{
    fout << "3.3. 판매 완료 상품 조회\n";
    sort(productsSoldOut.begin(), productsSoldOut.end());
    for(auto [name, company, price, stock] : productsSoldOut){
        fout << name << " " <<  company << " " << price << " " << stock << "\n\n"; //정보들을 vector<tuple<>>로 받아서, 상품 별로 출력
    }
}