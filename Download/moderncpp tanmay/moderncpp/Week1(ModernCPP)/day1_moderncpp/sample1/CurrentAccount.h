#ifndef CURRENTACCOUNT_H
#define CURRENTACCOUNT_H

#include<iostream>
#include "BankAccount.h"

class CurrentAccount : public BankAccount
{
private:
    
public:
    CurrentAccount() = default; //rather than initializing member functions one by one init it directly while defining variables using "defualt".
    CurrentAccount(const CurrentAccount&) = delete; //disable copy constructor
    CurrentAccount& operator=(const CurrentAccount&) = delete; //so that we CANNOT copy bank account.
    ~CurrentAccount() = default; //enable destructor

    //two new things in modern cpp
    CurrentAccount(CurrentAccount&&) = delete; //move constructor
    CurrentAccount& operator=(CurrentAccount&&) = delete; // move assignment. basically it is cut paste where it cuts values from RHS and pastes it in LHS.
    CurrentAccount(std::string name, float balance, DebitCard* card, float minBalance);
    CurrentAccount(std::string name,float balance, float minBalance);

    };

#endif // CURRENTACCOUNT_H
