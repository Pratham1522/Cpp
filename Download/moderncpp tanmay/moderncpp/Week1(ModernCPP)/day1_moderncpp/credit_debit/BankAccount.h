#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H
#include<iostream>

class BankAccount
{
private:
    static int counter;
    long _accountNumber {1000};
    std::string _accountName {""};
    float _accountBalance {5000.0f};
public:
    BankAccount()=default;
    ~BankAccount()=default; 
    BankAccount(const BankAccount&) = delete;
    BankAccount(const BankAccount&&) = delete;
    BankAccount& operator=(const BankAccount&&) = delete;
    BankAccount& operator=(const BankAccount&) = delete;

    BankAccount(std::string name, float balance);

    virtual void calculateInterest() = 0;

    float accountBalance() const { return _accountBalance; }

    std::string accountName() const { return _accountName; }
    void setAccountName(const std::string &accountName) { _accountName = accountName; }

    friend std::ostream &operator<<(std::ostream &os, const BankAccount &rhs);
}; 
    

#endif // BANKACCOUNT_H
