#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H
#include<iostream>
//#include "DebitCard.h"
#include "BankAccount.h"
    
class SavingsAccount : public BankAccount
{
private:
    float _savingsAccountMinimumBalance {5000.0f};
public:
    SavingsAccount() = default; //rather than initializing member functions one by one init it directly while defining variables using "defualt".
    SavingsAccount(const SavingsAccount&) = delete; //disable copy constructor
    SavingsAccount& operator=(const SavingsAccount&) = delete; //so that we CANNOT copy bank account.
    ~SavingsAccount() = default; //enable destructor

    //two new things in modern cpp
    SavingsAccount(SavingsAccount&&) = delete; //move constructor
    SavingsAccount& operator=(SavingsAccount&&) = delete; // move assignment. basically it is cut paste where it cuts values from RHS and pastes it in LHS.
    SavingsAccount(std::string name, float balance, DebitCard* card, float minBalance);
    SavingsAccount(std::string name,float balance, float minBalance);

    float savingsAccountMinimumBalance() const { return _savingsAccountMinimumBalance; }

    friend std::ostream &operator<<(std::ostream &os, const SavingsAccount &rhs);

    void CalculateInterest() override;
};

#endif // SAVINGSACCOUNT_H
