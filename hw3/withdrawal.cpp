#include "withdrawal.h"

using namespace std;

extern ifstream fin;
extern ofstream fout;
extern User* loginUser;

void Withdrawal::withdrawalUser()
{  
  fout << loginUser->getId() << "\n";
  
  loginUser->eraseId();
  loginUser = NULL;
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
