#include "bill.h"

Bill::Bill()
{
    billnumber=0;
    billamount=0;
}
void Bill::accept()
{
    std::cout<<"\nEnter bill number: ";
    std::cin>>billnumber;
    customerinfo.accept();
    billdate.accept();
}
Bill::~Bill()
{
    std::cout<<"yet to implement destructor";
    // delete customerinfo;
    // delete billdate;
}
int Bill::getBillnumber() const
{ 
    return billnumber; 
}
void Bill::setBillnumber(int billnumber_) 
{ 
    billnumber = billnumber_; 
}

std::ostream &operator<<(std::ostream &o, Bill &obj)
{
    // TODO: insert return statement here
    o<<"yet to implement in bill.cpp";
    return o;
}
