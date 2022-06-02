#include "signOut.h"
#include <fstream>

using namespace std;

extern ifstream fin;
extern ofstream fout;
extern User* loginUser;

/*
	함수 이름 : SignOut::signOut()
	기능	  : 로그아웃하려는 user의 id를 출력하고, 로그아웃 실행
	전달 인자 : 없음
	반환값    : 없음
    생성 일자 : 2022/5/31 6:00 PM
    작성자 :   이다연
*/
void SignOut::signOut()
{      
    fout <<"> "<< loginUser->getId() << "\n\n";

    loginUser = NULL;
}

/*
	함수 이름 : SignOut::run()
	기능	  : 로그인의 최초 함수, SignOutUI의 startInterface()를 실행함
	전달 인자 : 없음
	반환값    : 없음
    생성 일자 : 2022/5/31 6:00 PM
    작성자 :   이다연
*/
void SignOut::run()
{
    SignOutUI::startInterface();
}

/*
	함수 이름 : SignOut::signOutUser()
	기능	  : 로그아웃을 진행함
	전달 인자 : 없음
	반환값    : 없음
    생성 일자 : 2022/5/31 6:00 PM
    작성자 :   이다연
*/
void SignOutUI::signOutUser()
{
    fout<< "2.2. 로그아웃\n";
    SignOut::signOut();
}

/*
	함수 이름 : SignOut::printSignOutMessage()
	기능	  : 로그아웃 메시지를 출력함
	전달 인자 : 없음
	반환값    : 없음
    생성 일자 : 2022/5/31 6:00 PM
    작성자 :   이다연
*/
void SignOutUI::printSignOutMessage()
{
    signOutUser();    
}

/*
	함수 이름 : SignOut::startInterface()
	기능	  : 로그아웃을 위한 인터페이스를 출력함
	전달 인자 : 없음
	반환값    : 없음
    생성 일자 : 2022/5/31 6:00 PM
    작성자 :   이다연
*/
void SignOutUI::startInterface()
{
    printSignOutMessage();
}
