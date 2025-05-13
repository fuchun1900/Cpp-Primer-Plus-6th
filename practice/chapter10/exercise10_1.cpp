#include "Banker.h"
#include <iostream>
#include <string>

BankAccount::BankAccount()
{
    fullname = "";
    bankid = "";
    balance = 0.0;
}

BankAccount::BankAccount(const std::string &name ,const std::string &id , double bal)
{
    fullname = name;
    bankid = id;
    balance = bal;
}

BankAccount::~BankAccount()
{
    // Destructor
}

void BankAccount::show() const
{
    std::cout << "Name: " << fullname << "\n";
    std::cout << "Bank ID: " << bankid << "\n";
    std::cout << "Balance: $" << balance << "\n";
}

void BankAccount::save(double cash)
{
    if(cash < 0)
        std::cout << " Please enter the amount you want to save: (must bigger than zero) ";
    else
    {
        balance+= cash;
        std::cout << " You have saved: $" << cash << "\n";
    }
}

void BankAccount::take(double cash)
{
    if(cash < 0)
        std::cout << " Please enter the amount you want to take: (must bigger than zero) ";
    else if (cash > balance)
        std::cout << " You don't have enough money in your account! \n";
    else
    {
        balance-= cash;
        std::cout << " You have taken: $" << cash << "\n";
    }
}
