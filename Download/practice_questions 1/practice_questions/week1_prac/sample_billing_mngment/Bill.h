#ifndef BILL_H
#define BILL_H
#include<iostream>
#include "Date.h"
#include "Customer.h"
#include<memory>

class Bill
{
private:
    static int counter;
    int _billNumber {counter};
    std::shared_ptr<Customer> _customer;
    Date _billDate;
    int _billAmount {0};
public:
    Bill() = default;
    void accept();

    int billAmount() const { return _billAmount; }
    void setBillAmount(int billAmount) { _billAmount = billAmount; }

    void setBillNumber() { _billNumber = counter++; }

    friend std::ostream &operator<<(std::ostream &os, const Bill &rhs);
    ~Bill() = default;

    std::shared_ptr<Customer> customer() const { return _customer; }
    void setCustomer(const std::shared_ptr<Customer> &customer) { _customer = customer; }

};
#endif // BILL_H
