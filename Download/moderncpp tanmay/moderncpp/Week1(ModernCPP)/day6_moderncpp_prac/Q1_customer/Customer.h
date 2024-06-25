#ifndef CUSTOMER_H
#define CUSTOMER_H
#include<iostream>
#include "CustomerType.h"
#include <vector>
#include<array>

class Customer
{
private:
    int _customerId {0};
    std::string _customerName {""};
    CustomerType _customerType{CustomerType::REGULAR};
    std::array<double,5> _customerTransactionAmounts = {0.0f,0.0f,0.0f,0.0f,0.0f};
    double _customerStoreCredits;

public:
    Customer() = default;
    ~Customer() = default;
    Customer(const Customer&&) = delete;
    Customer(const Customer&) = default;
    Customer& operator=(const Customer&) = default;
    void operator+(const Customer&);
    Customer(int id, std::string name, CustomerType type, std::array<double,5>transactionamt, double credits);
    Customer(int id);
    int sumofarr(){
        return (_customerTransactionAmounts[0]+_customerTransactionAmounts[1]+_customerTransactionAmounts[2]+_customerTransactionAmounts[3]+_customerTransactionAmounts[4]);
    }

    int customerId() const { return _customerId; }

    std::string customerName() const { return _customerName; }
    void setCustomerName(const std::string &customerName) { _customerName = customerName; }

    CustomerType customerType() const { return _customerType; }

    double customerStoreCredits() const { return _customerStoreCredits; }

    void setCustomerTransactionAmounts(double customerTransactionAmounts[]) { 
        for(int i=0;i<5;i++){
            _customerTransactionAmounts[i] = customerTransactionAmounts[i];
        }
     }


    friend std::ostream &operator<<(std::ostream &os, const Customer &rhs);
};

#endif // CUSTOMER_H
