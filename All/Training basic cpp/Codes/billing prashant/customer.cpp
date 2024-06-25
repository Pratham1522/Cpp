#include "customer.h"
#include<cstring>
#include<string>


customer::customer()
{
    std::cout<<"Customer class constructor called !!\n";
    customer_name = new char[5];
    strcpy(customer_name,"#");
}

customer::customer(const char *name)
{
    customer_name = new char[strlen(name)+1];
    strcpy(customer_name,name);
}

void customer::setName(const char* name)
{
    strcpy(customer_name,name);
}

void customer::getName() const
{
    std::cout<<"Customer name is : "<<customer_name<<"\n";
}

void customer::accept()
{
    std::cout<<"Enter the name of customer : ";
    char* nn = new char[100];
    
    std :: cin.getline(nn,100);
    delete[] customer_name;
    customer_name = new char[strlen(nn) + 1];
    strcpy(customer_name,nn);



    // std::cin>>customer_name;
}

customer::~customer()
{
    std::cout<<"Deconstructor called\n";
    delete []customer_name;
}

std::ostream &operator<<(std::ostream &os, customer &other)
{
    os << other.customer_name<<"\n";
    return os;
}
