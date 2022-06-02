#include <iostream>
#include <fstream>
#include "signUp.h"
#include "withdrawal.h"
#include "SignIn.h"
// #include "logout.h"
#include "searchProduct.h"
#include "purchaseProduct.h"
#include "evaluateSatisfaction.h"
#include "checkPurchasedProduct.h"
#include "RegisterProduct.h"
#include "InquireSalesStatistics.h"
#include "InquireProductsForSale.h"
#include "InquireSoldOutProduct.h"


#define MAX_STRING 32
#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"

using namespace std;

void doTask();
void program_exit();

ifstream fin;
ofstream fout;

vector<Product> productDB;
User* loginUser = NULL;

int main()
{
    doTask();
    return 0;
}

void doTask()
{
    int menu_level_1, menu_level_2;
    int is_program_exit = 0;
    string name;
    
    
    fin.open(INPUT_FILE_NAME);
    fout.open(OUTPUT_FILE_NAME);
    while(!is_program_exit)
    {
        fin>> menu_level_1;
        fin>> menu_level_2;
        
        switch(menu_level_1)
        {
            case 1:
            {
                switch (menu_level_2) {
                    // 회원가입
                    case 1:
                    {
                        SignUp();
                        break;
                    }
                    // 회원탈퇴
                    case 2:
                    {
                        Withdrawal();
                        break;
                    }
                    default:
                        break;
                }
            }
            case 2:
            {
                switch (menu_level_2) {
                    // 로그인
                    case 1:
                    {
                        Login();
                        break;
                    }
                    // 로그아웃
                    case 2:
                    {
                        // Logout();
                        break;
                    }
                    default:
                        break;
                }
            }
            case 3:
            {
                switch (menu_level_2) {
                    case 1:
                    {
                        RegisterProduct::run();
                        break;
                    }
                    case 2:
                    {
                        InquireProductsForSale::run();
                        break;
                    }
                    case 3:
                    {
                        InquireSoldOutProduct::run();
                        break;
                    }
                    default:
                        break;
                }
            }

            case 4:
            {
                switch(menu_level_2)
                {
                    // 상품 정보 검색
                    case 1:
                        SearchProduct();
                        break;
                    // 상품 구매
                    case 2:
                        PurchaseProduct();
                        break;
                    // 상품 구매 내역 조회
                    case 3:
                        CheckPurchasedProduct();
                        break;
                    // 상품 구매만족도 평가
                    case 4:
                        EvaluateSatisfaction();
                        break;
                        
                    default:
                        break;
                }
                break;
            }
            default:
                is_program_exit = 1;
                break;

            case 5:
            {
                switch (menu_level_2) {
                    case 1:
                    {
                        InquireSalesStatistics::run();
                        break;
                    }
                    default:
                        break;
                }
                break;
            }

        }

    }
}

