#include "InquireSalesStatistics.h"
extern User* loginUser;

/*
	함수 이름 : InquireSalesStatistics::run(User *user)
	기능	  :   판매 통계 요청 시 실행, 판매 수량이 0이 아닌 상품들의 통계 정보를 InquireSalesStatisticsUI의 startInterface()에 전달한다.
	전달 인자 : vector<tuple<>> 으로 전달, 상품 명(string), 총 판매 가격(int), 평균 만족도(double)
	반환값    : 없음
    생성 일자 : 2022/5/30 7:00 PM
    작성자 :   김기선
*/
void InquireSalesStatistics::run()
{
    vector<tuple<string, int, double> > ret;
    for(Product product : loginUser->getSaleProductList().getOwnProduct()){
        if(product.getSalesQuantity()!=0){ //판매 수량이 1이상인 경우 체크
            ret.push_back({product.getName(), product.getTotalSales(), product.getAverageSatisfaction()});
        }
    }
    InquireSalesStatisticsUI::startInterface(ret);
}

/*
	함수 이름 : InquireSalesStatisticsUI::startInterface(vector<tuple<string, int, double> > productsSalesStatistics)
	기능	  : 판매자에게 요청한 상품들의 판매 통계 정보 출력
	전달 인자 : vector<tuple<>> 으로 전달, 상품 명(string), 총 판매 가격(int), 평균 만족도(double)
	반환값    : 없음
    생성 일자 : 2022/5/30 7:00 PM
    작성자 :   김기선
*/
void InquireSalesStatisticsUI::startInterface(vector<tuple<string, int, double> > productsSalesStatistics)
{
    fout << "5.1. 판매 상품 통계\n";
    for(auto [name, totalSales, averageSatisfaction] : productsSalesStatistics){
        fout << name << " " << totalSales << " " << averageSatisfaction << "\n\n";
    }
}