#include "Customer.h"



void Customer::operator+(const Customer &rhs)
{   
    double total_amount = 0.0f;
    total_amount = this->customerStoreCredits() + rhs.customerStoreCredits();
    std::cout<<"Sum of total credits is: "<<total_amount;
}

Customer::Customer(int id, std::string name, CustomerType type, std::array<double,5>transactionamt, double credits)
    : _customerId(id), _customerName(name), _customerType(type), _customerTransactionAmounts(transactionamt), _customerStoreCredits(credits)
{
}

Customer::Customer(int id)
    : _customerId(id)
{
}

std::ostream &operator<<(std::ostream &os, const Customer &rhs)
{
    os << "_customerId: " << rhs._customerId
       << " _customerName: " << rhs._customerName
       << " _customerType: " ; 
       if(static_cast<int>(rhs._customerType)==0){
        os<<"PREMIUM";
       }
        else if(static_cast<int>(rhs._customerType)==1){
            os<<"REGULAR";
        }
        else if(static_cast<int>(rhs._customerType)==2){
            os<<"VIP";
        }
       os<< " _customerTransactionAmounts: ";
       for(int i=0;i<5;i++){
       os<<rhs._customerTransactionAmounts[i];}
       os<< " _customerStoreCredits: " << rhs._customerStoreCredits;
    return os;
}
