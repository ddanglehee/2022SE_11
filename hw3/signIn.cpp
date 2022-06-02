#include "signIn.h"
#include <fstream>

using namespace std;

extern ifstream fin;
extern ofstream fout;
extern UserCollection user;

void SignIn::signIn(string id, string password)
{
  if(user.checkValidation)
  {
    fout<< "2.1. 로그인\n";
    fout<< ">" << id << " " << password << "\n";
  }
}

void SignIn::run()
{
  SignInUI::startInterface();
}

void SignInUI::submitForm(string id, string password)
{
  SignIn::signIn(id, password);
}

void SignInUI::startInterface()
{
  string id, password;
  fin >> id >> password;
  submitForm(id, password);
}
