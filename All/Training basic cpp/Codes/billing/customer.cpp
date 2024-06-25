#include "customer.h"


customer::customer()
{
     customername = new char[10];
     strcpy(customername,"Bob");
}

customer::customer(const char *name)
{
    customername = new char[strlen(name)+1];
    strcpy(customername,name);
}

customer::customer(customer &other)
{
    customername = new char[strlen(other.customername)+1];
    strcpy(customername,other.customername);
}

void customer::accept()
{
    customername = new char[10];
    std::cout<<"Enter the customer name"<<std::endl;
    std::cin>>customername;
    std::cout<<std::endl;
}

std::ostream& operator <<(std::ostream& out, customer& p)
{
    out<<"Customer Name is"<<std::endl;
    out<<p.customername<<std::endl;
    out<<std::endl;
    return out;
}

customer::~customer()
{
    delete customername;
}