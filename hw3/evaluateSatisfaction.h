#ifndef evaluateSatisfaction_h
#define evaluateSatisfaction_h
#include <iostream>
#include <fstream>
#include <vector>
#include "product.h"

using namespace std;

extern ifstream fin;
extern ofstream fout;
extern vector<Product> productDB;

class EvaluateSatisfaction;

class EvaluateSatisfactionUI
{
private:
    EvaluateSatisfaction* controller;
public:
    EvaluateSatisfactionUI(EvaluateSatisfaction* controller);
    void evaluateSatisfaction(string targetProductName);
};

class EvaluateSatisfaction
{
private:
    EvaluateSatisfactionUI* boundary;
public:
    EvaluateSatisfaction();
    string updateAverageSatisfaction(string targetProductName, int satisfaction);
};

#endif /* evaluateSatisfaction_h */
