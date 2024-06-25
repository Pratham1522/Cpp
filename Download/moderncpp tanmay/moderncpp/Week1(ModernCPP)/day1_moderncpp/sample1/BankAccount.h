#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H
#include "DebitCard.h"

class BankAccount
{
private:
    static long _counter;
    long _accountNumber  {900000};
    std::string  _accountHolderName {""};
    float _accountBalance {0.0f};
    DebitCard* _accountDebitCard {nullptr};
public:
    BankAccount() = default; //rather than initializing member functions one by one init it directly while defining variables using "defualt".
    BankAccount(const BankAccount&) = delete; //disable copy constructor
    BankAccount& operator=(const BankAccount&) = delete; //so that we CANNOT copy bank account.
    ~BankAccount() = default; //enable destructor

    //two new things in modern cpp
    BankAccount(BankAccount&&) = delete; //move constructor
    BankAccount& operator=(BankAccount&&) = delete; // move assignment. basically it is cut paste where it cuts values from RHS and pastes it in LHS.

    BankAccount(std::string name, float balance);
    BankAccount(std::string name, float balance, DebitCard* card);

    long accountNumber() const { return _accountNumber; }

    std::string accountHolderName() const { return _accountHolderName; }
    void setAccountHolderName(const std::string &accountHolderName) { _accountHolderName = accountHolderName; }

    float accountBalance() const { return _accountBalance; }

    friend std::ostream &operator<<(std::ostream &os, const BankAccount &rhs);
    friend std::istream &operator>>(std::istream &in, const BankAccount &rhs);
    virtual void CalculateInterest() = 0;

    DebitCard* accountDebitCard() const { return _accountDebitCard; }
    void setAccountDebitCard(DebitCard* accountDebitCard) { _accountDebitCard = accountDebitCard; }
};

#endif // BANKACCOUNT_H
