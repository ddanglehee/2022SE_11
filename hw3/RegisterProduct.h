#include"product.h"
#include"user.h"
#include<fstream>
using namespace std;

extern ifstream fin;
extern ofstream fout;

class RegisterProductUI;

class RegisterProduct {
private:
    RegisterProductUI* boundary;
public:
    static void addNewProduct(string name, string company, int price, int stock);
    static void run();
};

class RegisterProductUI{
private:
    RegisterProduct* controller;
public:
    static void startInterface();
    static void registerProduct(string name, string company, int price, int stock);
    static void printRegisterCompleteMessage(string name, string company, int price, int stock);
};



    