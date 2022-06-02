#include"user.h"
#include"product.h"
#include<tuple>
#include<algorithm>
#include<fstream>

extern ifstream fin;
extern ofstream fout;

class InquireSoldOutProductUI;

class InquireSoldOutProduct {
private:
    InquireSoldOutProductUI* boundary;
public:
    static void run();
};

class InquireSoldOutProductUI {
private:
    InquireSoldOutProduct* controller;
public:
    static void startInterface(vector<tuple<string, string, int, int> > productsSoldOut);
};


