#include "bill.h"
#include"customer.h"
#include"date.h"

bill::bill()
{
    bill_number=0;
    bill_amount=0;
}

void bill::setBillNumber(int bn)
{
    bill_number = bn;
}

void bill::setBillAmount(int ba)
{
    bill_amount = ba;
}

void bill::getAll()
{
    customer_info.getName();
    bill_date.getAll();
    std::cout<<"Bill number is : "<<bill_number<<'\n';
    std::cout<<"Bill amount is : "<<bill_amount<<'\n';
}

int bill::getBill() const
{
    return bill_amount;
}

void bill::accept()
{
    customer_info.accept();
    bill_date.accept();

    std::cout <<"Enter the bill number : ";
    std::cin>>bill_number;

    std::cout<<"Enter the bill amount : ";
    std::cin>>bill_amount;
    std::cin.get();
    // std::cin.clear(std::)
}

bill::~bill()
{
    std::cout<<"Bill class constructor called\n";
}
