#include <iostream>
#include <fstream>
#include <vector>
#include "user.h"

using namespace std;

class SignUpUI;

class SignUp {
private:
    SignUpUI* boundary;
public:
    static void addNewUser(string name, string rrn, string id, string password);
    static void run();
};

class SignUpUI {
private:
    SignUp* controller;
public:
    static void submitForm(string name, string rrn, string id, string password);
    static void startInterface();
};
