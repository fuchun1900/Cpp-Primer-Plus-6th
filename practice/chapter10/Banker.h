#ifndef BANKER_H_
#define BANKER_H_
#include <iostream>
#include <string>


class BankAccount
{
    private:
        std::string fullname;
        std::string bankid;
        double balance;
    
    public:
        BankAccount();
        BankAccount(const std::string &name ,const std::string &id , double bal);
        ~BankAccount();
        void show() const;
        void save(double cash);
        void take(double cash);

};



#endif