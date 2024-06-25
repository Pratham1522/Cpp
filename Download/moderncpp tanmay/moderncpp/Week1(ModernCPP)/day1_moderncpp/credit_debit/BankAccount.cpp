#include "BankAccount.h"

int BankAccount::counter = 1000;

BankAccount::BankAccount(std::string name, float balance)
    :_accountName{_accountName}, _accountBalance{balance}, _accountNumber{counter++}
    {}

std::ostream &operator<<(std::ostream &os, const BankAccount &rhs) {
    os << "_accountNumber: " << rhs._accountNumber
       << " _accountName: " << rhs._accountName
       << " _accountBalance: " << rhs._accountBalance;
    return os;
}
