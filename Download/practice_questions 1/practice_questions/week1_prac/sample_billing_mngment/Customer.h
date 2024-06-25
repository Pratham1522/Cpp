#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <iostream>

class Customer
{
private:
    char *_customerName {nullptr};
public:
    Customer() = default;
    ~Customer() = default;
    Customer(Customer &rhs) = default;
    Customer &operator=(const Customer &rhs) = default;

    friend std::ostream &operator<<(std::ostream &os, const Customer &rhs);
    Customer(char *customerName);
    void accept();

    char *customerName() const { return _customerName; }
    void setCustomerName(char *customerName) { _customerName = customerName; }

    friend std::ostream &operator<<(std::ostream &os, const Customer &rhs);
    
};

#endif // CUSTOMER_H
