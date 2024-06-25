#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "CustomerType.h"
#include <iostream>
#include<array>

class Customer 
{
private:
    static int iden;
    int identity;
    unsigned int _customerId{0};
    std::string _customerName {""};
    CustomerType _customerType {CustomerType::REGULAR};
    int* _customerTransactionAmount{nullptr};

    // std::array<int,5> _customerTransactionAmount;
    int _customerStoreCredits {5000};
public:
    Customer() = default; // Default constructor
    Customer(const Customer&) = default; // Copy constructor
    Customer& operator=(const Customer&) = delete; // Copy assignment operator
    Customer(Customer&&) = delete; // Move constructor
    Customer& operator=(Customer&&) = delete; // Move assignment operator
    ~Customer() {delete[] _customerTransactionAmount;} // Destructor

    void operator+(Customer &rhs);

    //Customer(unsigned int id, std::string name, CustomerType type, std::array<int,5> array);
    Customer(unsigned int id, std::string name, CustomerType type,int* arr);

    Customer(unsigned int id);

    unsigned int customerId() const { return _customerId; }

    std::string customerName() const { return _customerName; }
    void setCustomerName(const std::string &customerName) { _customerName = customerName; }

    CustomerType customerType() const { return _customerType; }
    void setCustomerType(const CustomerType &customerType) { _customerType = customerType; }

   
    int customerStoreCredits() const { return _customerStoreCredits; }
    void setCustomerStoreCredits(int customerStoreCredits) { _customerStoreCredits = customerStoreCredits; }

    int* customerTransactionAmount() const { return _customerTransactionAmount; }
    void setCustomerTransactionAmount(int* customerTransactionAmount) { _customerTransactionAmount = customerTransactionAmount; }


    // std::array<int,5> customerTransactionAmount() const { return _customerTransactionAmount; }
    // void setCustomerTransactionAmount(const std::array<int,5> &customerTransactionAmount) { _customerTransactionAmount = customerTransactionAmount; }

  
    friend std::ostream &operator<<(std::ostream &os, const Customer &rhs);
};

#endif // CUSTOMER_H
