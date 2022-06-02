#include <iostream>
#include <fstream>
#include <vector>
#include "user.h"

using namespace std;

class WithDrawalUI;

class Withdrawal {
private:
    WithDrawalUI* boundary;
public:
    static void withdrawalUser();
    static void run();
};

class WithdrawalUI {
private:
    Withdrawal* controller;
public:
    static void requestWithdrawal();
    static void startInterface();
};


