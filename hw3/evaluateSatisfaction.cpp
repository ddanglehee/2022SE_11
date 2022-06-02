#include "evaluateSatisfaction.h"

/*
    함수 이름 : EvaluateSatisfaction::EvaluateSatisfaction()
    기능      : EvaluateSatisfaction 생성자
    전달 인자 : 없음
    반환값    : 없음
    생성 일자 : 2022/6/2 11:00 PM
    작성자 :   장성희
*/
EvaluateSatisfaction::EvaluateSatisfaction()
{
    EvaluateSatisfactionUI boundary = EvaluateSatisfactionUI(this);
    this->boundary = &boundary;
}

/*
    함수 이름 : EvaluateSatisfactionUI::EvaluateSatisfactionUI(EvaluateSatisfaction* controller)
    기능      : EvaluateSatisfactionUI 생성자
    전달 인자 : EvaluateSatisfaction의 참조
    반환값    : 없음
    생성 일자 : 2022/6/2 11:00 PM
    작성자 :   장성희
*/
EvaluateSatisfactionUI::EvaluateSatisfactionUI(EvaluateSatisfaction* controller)
{
    this->controller = controller;
    fout<< "4.4. 상품 구매만족도 평가"<< endl;
    
    string targetProductName;
    fin>> targetProductName;
    
    evaluateSatisfaction(targetProductName);
}

/*
    함수 이름 : EvaluateSatisfactionUI::evaluateSatisfaction(string targetProductName)
    기능      : 구매만족도를 입력받아서 업데이트
    전달 인자 : 구매만족도를 입력할 상품의 상품명(string)
    반환값    : 없음
    생성 일자 : 2022/6/2 11:00 PM
    작성자 :   장성희
*/
void EvaluateSatisfactionUI::evaluateSatisfaction(string targetProductName)
{
    int satisfaction;
    fin>> satisfaction;
    string sellerId = this->controller->updateAverageSatisfaction(targetProductName, satisfaction);
    fout<< "> "<< sellerId<< " "<< targetProductName<< " "<< satisfaction<< endl<< endl;
}

/*
    함수 이름 : EvaluateSatisfaction::updateAverageSatisfaction(string targetProductName, int satisfaction)
    기능      : 구매만족도를 업데이트
    전달 인자 : 구매만족도를 입력할 상품의 상품명, 구매만족도
    반환값    : 구매만족도를 입력한 상품의 판매자 ID(string)
    생성 일자 : 2022/6/2 11:00 PM
    작성자 :   장성희
*/
string EvaluateSatisfaction::updateAverageSatisfaction(string targetProductName, int satisfaction)
{
    for(auto& ptr: productDB)
    {
        if(ptr.getName() == targetProductName)
        {
            ptr.updateAverageSatisfaction(satisfaction);
            return ptr.getSellerId();
        }
    }
    return "";
}
