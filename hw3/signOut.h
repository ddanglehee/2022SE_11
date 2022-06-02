#include <iostream>
#include <fstream>
#include <vector>
#include "user.h"

using namespace std;

class SignOutUI;

class SignOut {
private:
  SignOutUI* boundary;
public:
  static void signOut();
  static void run();
};

class SignOutUI {
private:
  SignOut* controller;
public:
  static void signOutUser();
  static void printSignOutMessage();
  static void startInterface();
}
