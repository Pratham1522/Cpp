#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H
#include "BankAccount.h"
#include <ostream>

class SavingsAccount:public BankAccount
{
private:
    float _minimumBalance {5000.0f};
public:
    SavingsAccount()=default;
    ~SavingsAccount()=default; 
    SavingsAccount(const SavingsAccount&) = delete;
    SavingsAccount(const SavingsAccount&&) = delete;
    SavingsAccount& operator=(const SavingsAccount&&) = delete;
    SavingsAccount& operator=(const SavingsAccount&) = delete;

    SavingsAccount(std::string name, long balance, float minBalance);

    float minimumBalance() const { return _minimumBalance; }

    friend std::ostream &operator<<(std::ostream &os, const SavingsAccount &rhs);
    void calculateInterest() override;
};

#endif // SAVINGSACCOUNT_H
