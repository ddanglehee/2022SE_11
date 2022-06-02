#include <iostream>
#include <fstream>
#include <vector>
#include "user.h"

using namespace std;

class SignInUI;

class SignIn {
private:
  SignInUI* boundary;
public:
  static void signIn(string id, string password);
  static void run();
};

class SignInUI {
private:
  SignIn* controller;
public:
  static void submitForm(string id, string password);
  static void startInterface();
};
