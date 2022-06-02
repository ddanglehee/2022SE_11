#include "signUp.h"
#include <fstream>

using namespace std;

extern ifstream fin;
extern ofstream fout;
extern User user;

/*
	함수 이름 : SignUp::addNewUser(string name, string rrn, string id, string password)
	기능	  : 회원 정보를 입력하여 회원가입을 진행함
	전달 인자 : 이름, 주민번호, 아이디, 비밀번호
	반환값    : 없음
    생성 일자 : 2022/5/31 7:00 PM
    작성자 :   이다연
*/
void SignUp::addNewUser(string name, string rrn, string id, string password)
{   
    user.addUser(name, rrn, id, password);
    fout<< "1.1. 회원가입\n";
    fout<< ">" << name << " " << rrn << " " << id << " " << password << "\n";
}

/*
	함수 이름 : SignUp::run()
	기능	  :  회원가입의 최초 함수, RegisterProductUI의 startInterface()를 실행함
	전달 인자 : 없음
	반환값    : 없음
    생성 일자 : 2022/5/31 7:00 PM
    작성자 :   이다연
*/
void SignUp::run()
{
    SignUpUI::startInterface();
}

/*
	함수 이름 : SignUpUI::submitForm(string name, string rrn, string id, string password)
	기능	  : 로그인 폼을 제출함
	전달 인자 : 이름, 주민번호 아이디, 비밀번호
	반환값    : 없음
    생성 일자 : 2022/5/31 7:00 PM
    작성자 :   이다연
*/
void SignUpUI::submitForm(string name, string rrn, string id, string password)
{
    SignUp::addNewUser(name, rrn, id, password);
}

/*
	함수 이름 : SignUpUI::startInterface()
	기능	  : 회원가입을 위한 인터페이스를 출력함
	전달 인자 : 없음
	반환값    : 없음
    생성 일자 : 2022/5/31 7:00 PM
    작성자 :   이다연
*/
void SignUpUI::startInterface()
{
    string name, rrn, id, password;
    fin >> name >> rrn >> id >> password;
    submitForm(name, rrn, id, password);    
}
