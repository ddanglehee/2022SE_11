#include "withdrawal.h"

using namespace std;

extern ifstream fin;
extern ofstream fout;
extern User* loginUser;

/*
	함수 이름 : Withdrawal::withdrawalUser()
	기능	  : 회원 탈퇴를 진행함
	전달 인자 : 없음
	반환값    : 없음
  생성 일자 : 2022/6/2 3:00 PM
  작성자 :   이다연
*/
void Withdrawal::withdrawalUser()
{  
  fout<< "1.2. 회원탈퇴\n";
  fout << loginUser->getId() << "\n";
  
  loginUser->eraseId();
  loginUser = NULL;
}

/*
	함수 이름 : Withdrawal::run()
	기능	  : 회원탈퇴의 최초 함수, WithdrawalUI의 startInterface()를 실행함
	전달 인자 : 없음
	반환값    : 없음
  생성 일자 : 2022/6/2 3:00 PM
  작성자 :   이다연
*/
void Withdrawal::run()
{
  WithdrawalUI::startInterface();
}

/*
	함수 이름 : WithdrawalUI::requestWithdrawal()
	기능	  : 회원 탈퇴를 요청함
	전달 인자 : 없음
	반환값    : 없음
  생성 일자 : 2022/6/2 3:00 PM
  작성자 :   이다연
*/
void WithdrawalUI::requestWithdrawal()
{
  Withdrawal::withdrawalUser();
}

/*
	함수 이름 : WithdrawalUI::startInterface()
	기능	  : 회원 탈퇴를 위한 인터페이스를 출력함
	전달 인자 : 없음
	반환값    : 없음
  생성 일자 : 2022/6/2 3:00 PM
  작성자 :   이다연
*/
void WithdrawalUI::startInterface()
{
  requestWithdrawal();
}
