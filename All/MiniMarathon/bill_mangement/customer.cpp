#include "customer.h"
#include <cstring>

Customer::Customer()
{
    customername=new char[100];
}

Customer::Customer(char *name)
{
    customername= new char[strlen(name)+1];
    strcpy(customername,name);
}

Customer::Customer(Customer &obj1)
{
    customername = new char [strlen(obj1.getCustomername())+1];
    strcpy(customername , obj1.getCustomername());
}
//getters n setters
char* Customer::getCustomername() const {
     return customername; 
}
void Customer::setCustomername(char* customername_) 
{ 
    customername = customername_; 
}

void Customer::accept()
{
    std::cout<<"Enter Customer Name : ";
    std::cin.getline(customername,strlen(customername));
    std::cout<<"\n"<<customername<<"\n";
}

std::ostream& operator<<(Customer &obj,std::ostream &o){
    o << "\nName: " << obj.getCustomername();
    return o;
}
Customer::~Customer(){
    delete []customername;
}