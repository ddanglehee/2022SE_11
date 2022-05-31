#include <iostream>
#include <fstream>
#include <vector>
#include "product.h"
#include "user.h"


using namespace std;

class SignUpUI;

class SignUp
{
private:
    SignUpUI* boundary;
public:
    SignUp();
    bool signUp();
};

class SignUptUI
{
private:
    SignUp* controller;
public:
    SignUpUI(SignUp* controller);
    void signUp();
};


