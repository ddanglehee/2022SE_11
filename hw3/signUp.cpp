#include "signUp.h"
#include <fstream>

using namespace std;

extern ifstream fin;
extern ofstream fout;
extern UserCollection user;

void SignUp::addNewUser(string name, string rrn, string id, string password)
{   
    user.addUser(name, rrn, id, password);
    fout<< "1.1. 회원가입\n";
    fout<< ">" << name << " " << rrn << " " << id << " " << password << "\n";
}

void SignUp::run()
{
    SignUpUI::startInterface();
}

void SignUpUI::submitForm(string name, string rrn, string id, string password)
{
    SignUp::addNewUser(name, rrn, id, password);
}

void SignUpUI::startInterface()
{
    string name, rrn, id, password;
    fin >> name >> rrn >> id >> password;
    submitForm(name, rrn, id, password);    
}