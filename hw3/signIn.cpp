#include <fstream>
#include <iostream>
#include "signIn.h"

using namespace std;

extern ifstream fin;
extern ofstream fout;
extern User user;

/*
	함수 이름 : SignIn::signIn(string id, string password)
	기능	  : id와 password를 보고 유효한 회원인지 확인한 후, 유효하다면 로그인 실행 
	전달 인자 : 아이디, 비밀번호
	반환값    : 없음
  생성 일자 : 2022/5/31 6:00 PM
  작성자 :   이다연
*/
void SignIn::signIn(string id, string password)
{
  if(user.checkValidation(id, password))
  {
    fout<< "2.1. 로그인\n";
    fout<< ">" << id << " " << password << "\n";
  }
}

/*
	함수 이름 : SignIn::run()
	기능	  : 로그인의 최초 함수, SignInUI의 startInterface()를 실행함
	전달 인자 : 없음
	반환값    : 없음
  생성 일자 : 2022/5/31 6:00 PM
  작성자 :   이다연
*/
void SignIn::run()
{
  SignInUI::startInterface();
}

/*
	함수 이름 : SignIn::submitForm()
	기능	  : 로그인 폼을 제출함
	전달 인자 : 아이디, 비밀번호
	반환값    : 없음
  생성 일자 : 2022/5/31 6:00 PM
  작성자 :   이다연
*/
void SignInUI::submitForm(string id, string password)
{
  SignIn::signIn(id, password);
}

/*
	함수 이름 : SignIn::startInterface()
	기능	  : 로그인을 위한 인터페이스를 출력함
	전달 인자 : 없음
	반환값    : 없음
  생성 일자 : 2022/5/31 6:00 PM
  작성자 :   이다연
*/
void SignInUI::startInterface()
{
  string id, password;
  fin >> id >> password;
  submitForm(id, password);
}
