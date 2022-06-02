#include"user.h"
#include"product.h"
#include<tuple>
#include<fstream>

extern ifstream fin;
extern ofstream fout;

class InquireSalesStatisticsUI;

class InquireSalesStatistics {
private:
    InquireSalesStatisticsUI* boundary;
public:
    static void run();
};

class InquireSalesStatisticsUI {
private:
    InquireSalesStatistics* controller;
public:
    static void startInterface(vector<tuple<string, int, double> > productsSalesStatistics);
};


