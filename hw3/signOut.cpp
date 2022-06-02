#include "signOut.h"
#include <fstream>

using namespace std;

extern ifstream fin;
extern ofstream fout;
extern UserCollection user;

void SignOut::signOut()
{      
    // 로그아웃한 회원의 id 출력하기
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
