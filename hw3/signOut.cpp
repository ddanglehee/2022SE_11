#include "signOut.h"
#include <fstream>

using namespace std;

extern ifstream fin;
extern ofstream fout;
extern User* loginUser;

void SignOut::signOut()
{      
    fout << loginUser->getId() << "\n";

    loginUser = NULL;
}

void SignOut::run()
{
    SignOutUI::startInterface();
}

void SignOutUI::signOutUser()
{
    SignOut::signOut();
}

void SignOutUI::printSignOutMessage()
{
    fout<< "2.2. 로그아웃\n";
    signOutUser();    
}

void SignOutUI::startInterface()
{
    printSignOutMessage();
}
