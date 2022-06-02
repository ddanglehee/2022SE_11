#include "withdrawal.h"

using namespace std;

extern ifstream fin;
extern ofstream fout;
extern UserCollection user;

void Withdrawal::withdrawalUser()
{  
  vector<User> userList = user.getUserList();
  int userCount = user.getUserDBSize();

  // 탈퇴한 회원의 id 출력하기
  
  // for(int i = 0; i < userCount; i++)
  // {
  //   if()
  // }
  

}

void Withdrawal::run()
{
  WithdrawalUI::startInterface();
}

void WithdrawalUI::requestWithdrawal()
{
  Withdrawal::withdrawalUser();
}

void WithdrawalUI::startInterface()
{
  fout<< "1.2. 회원탈퇴\n";
  requestWithdrawal();
}
