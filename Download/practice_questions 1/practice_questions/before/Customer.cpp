#include "Customer.h"

void Customer::operator+(Customer &rhs)
{
    // TODO: insert return statement here
    int answer = this->customerStoreCredits() + rhs.customerStoreCredits();
    this->setCustomerStoreCredits(answer);
    std::cout<<"sum is : "<<this->customerStoreCredits();
    
}

// Customer::Customer(unsigned int id, std::string name, CustomerType type, std::array<int,5> array)
//     :_customerId(id), _customerName(name), _customerType(type), _customerTransactionAmount(array)
// {
//     // for(int i=0;i<5;i++){
//     //     this->_customerTransactionAmount[i] = array[i];
//     // }
//}

int Customer::iden=1;
Customer::Customer(unsigned int id, std::string name, CustomerType type, int *arr)
    :_customerId(id), _customerName(name), _customerType(type), _customerTransactionAmount(arr), identity{iden++}
{
}

Customer::Customer(unsigned int id)
    : _customerId(id)
{
}


std::ostream &operator<<(std::ostream &os, const Customer &rhs) {
    os<<"id is: "<<rhs.identity;
    os << "_customerId: " << rhs._customerId
       << " _customerName: " << rhs._customerName
       << " _customerType: " ;
       if(static_cast<int>(rhs._customerType)==0){
        os<<"REGULAR";
       }
       else if(static_cast<int>(rhs._customerType)==1){
        os<<"PREMIUM";
       }
       else if(static_cast<int>(rhs._customerType)==2){
        os<<"VIP";
       }
       //os<< " _customerTransactionAmount: " << rhs._customerTransactionAmount
       for(int i=0;i<5;i++){
        os<<*(rhs._customerTransactionAmount+i)<<" ";
       }
       os<< " _customerStoreCredits: " << rhs._customerStoreCredits;
    return os;
}
