#include<iostream>
#include "BankAccount.h"

long BankAccount::_counter = 900000L;

std::ostream &operator<<(std::ostream &os, const BankAccount &rhs) {
    os << "_accountNumber: " << rhs._accountNumber
       << " _accountHolderName: " << rhs._accountHolderName
       << " _accountBalance: " << rhs._accountBalance;
    os
       << " _accountDebitCard: " << *rhs._accountDebitCard;
    return os;
}

std::istream &operator>>(std::istream &in, BankAccount &rhs)
{
    std::cout<<"Enter name: ";
    std::string name;
    in >> name;
    rhs.setAccountHolderName(name);
    return in;
}

BankAccount::BankAccount(std::string name, float balance)
    :_accountBalance{balance}, _accountHolderName{name}, _accountNumber{_counter++}
{   
}

BankAccount::BankAccount(std::string name, float balance, DebitCard *card)
    : BankAccount(name, balance) //constructor delegation reduces data duplication
{
_accountDebitCard = card;   
}

void BankAccount::CalculateInterest(){
    
}
