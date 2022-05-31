#include "evaluateSatisfaction.h"

EvaluateSatisfaction::EvaluateSatisfaction()
{
    EvaluateSatisfactionUI boundary = EvaluateSatisfactionUI(this);
    this->boundary = &boundary;
}

EvaluateSatisfactionUI::EvaluateSatisfactionUI(EvaluateSatisfaction* controller)
{
    this->controller = controller;
    fout<< "4.4. 상품 구매만족도 평가"<< endl;
    
    string targetProductName;
    fin>> targetProductName;
    
    evaluateSatisfaction(targetProductName);
}

void EvaluateSatisfactionUI::evaluateSatisfaction(string targetProductName)
{
    int satisfaction;
    fin>> satisfaction;
    string sellerId = this->controller->updateAverageSatisfaction(targetProductName, satisfaction);
    fout<< "> "<< sellerId<< " "<< targetProductName<< " "<< satisfaction<< endl<< endl;
}

string EvaluateSatisfaction::updateAverageSatisfaction(string targetProductName, int satisfaction)
{
    vector<Product>::iterator ptr;
    for(ptr = productDB.begin(); ptr < productDB.end(); ptr++)
    {
        if(ptr->getName() == targetProductName)
        {
            ptr->updateAverageSatisfaction(satisfaction);
            return ptr->getSellerId();
        }
    }
    return "";
}
