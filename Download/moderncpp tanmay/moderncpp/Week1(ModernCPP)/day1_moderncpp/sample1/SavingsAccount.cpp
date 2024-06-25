#include "SavingsAccount.h"

std::ostream &operator<<(std::ostream &os, const SavingsAccount &rhs) {
    os << static_cast<const BankAccount &>(rhs)
       << " _savingsAccountMinimumBalance: " << rhs._savingsAccountMinimumBalance;
    return os;
}

SavingsAccount::SavingsAccount(std::string name, float balance, float minBalance)
    :BankAccount(name,balance), _savingsAccountMinimumBalance{minBalance}
{
}

SavingsAccount::SavingsAccount(std::string name, float balance, DebitCard *card, float minBalance)
    :BankAccount(name,balance,card), _savingsAccountMinimumBalance{minBalance}
{
}

void SavingsAccount::CalculateInterest()
{
    std::cout<<"INterest on savings account is 4% "<<0.04*savingsAccountMinimumBalance();
}
