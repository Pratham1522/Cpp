#ifndef CUSTOMER_H
#define CUSTOMER_H
#include "Account.h"
#include <iostream>

class Customer :public Account
{
private:
    std::string _customerName{""};
public:
    Customer() = default; // Default constructor
    Customer(const Customer&) = default; // Copy constructor
    Customer& operator=(const Customer&) = delete; // Copy assignment operator
    Customer(Customer&&) = delete; // Move constructor
    Customer& operator=(Customer&&) = delete; // Move assignment operator
    ~Customer() = default; // Destructor

    Customer(std::string name);

    void registerstatus() override;
    std::string customerName() const { return _customerName; }
    void setCustomerName(const std::string &customerName) { _customerName = customerName; }
};

#endif // CUSTOMER_H
