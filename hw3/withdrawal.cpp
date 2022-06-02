#include "withdrawal.h"

using namespace std;

extern ifstream fin;
extern ofstream fout;
extern UserCollection user;

void Withdrawal::withdrawalUser()
{  
  vector<User> userList = user.getUserList();
  int userCount = user.getUserDBSize();

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
  requestWithdrawal();
}
