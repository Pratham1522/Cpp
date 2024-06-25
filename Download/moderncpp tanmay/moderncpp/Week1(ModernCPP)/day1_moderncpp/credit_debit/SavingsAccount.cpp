#include "SavingsAccount.h"

SavingsAccount::SavingsAccount(std::string name, long balance, float minBalance)
    :BankAccount(name,balance),_minimumBalance{minBalance}
{
}
void SavingsAccount::calculateInterest()
{
    std::cout<<"Interest for savings account is 4% "<<0.04*minimumBalance()<<'\n';
}
std::ostream &operator<<(std::ostream &os, const SavingsAccount &rhs)
{
    os << static_cast<const BankAccount &>(rhs)
       << " _minimumBalance: " << rhs._minimumBalance;
    return os;
}
