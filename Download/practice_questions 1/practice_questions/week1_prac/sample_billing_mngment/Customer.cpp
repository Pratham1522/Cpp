#include "Customer.h"
#include<string.h>

Customer::Customer(char *customerName)
{
    _customerName = new char[strlen(customerName)+1];
    strcpy(customerName,_customerName);
}


void Customer::accept()
{
    std::string name;
    char* ptr = new char[100];
    std::cout<<"Enter customer name: "<<std::endl;
    std::cin>>ptr;
    setCustomerName(ptr);
    delete[] ptr;
}
std::ostream &operator<<(std::ostream &os, const Customer &rhs) {
    os << "_customerName: " << rhs.customerName();
    return os;
}

int main(){
    Customer c;
    c.accept();
    std::cout<<c;
}