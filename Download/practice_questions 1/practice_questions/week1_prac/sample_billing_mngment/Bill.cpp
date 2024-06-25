#include "Bill.h"
#include<iostream>

std::ostream &operator<<(std::ostream &os, const Bill &rhs) {
    os << "_billNumber: " << rhs._billNumber
       << " _customerInfo: " << *rhs._customer
       << " _billDate: " << rhs._billDate
       << " _billAmount: " << rhs._billAmount;
    return os;
}

void Bill::accept()
{
    setBillNumber();
    std::cout<<"Enter bill amount: ";
    int amt;
    std::cin>>amt;
    setBillAmount(amt);
    _customer.accept();
    _billDate.accept();
}
int Bill::counter=100;
