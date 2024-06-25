#ifndef BILL_H
#define BILL_H

#include <iostream>
#include "Invoice.h"
#include<functional>

using InvoiceRef = std::reference_wrapper<Invoice>;

class Bill 
{
private:
    float _billAmount{0.0f};
    InvoiceRef _invoice;

public:
    Bill() = default; // Default constructor
    Bill(const Bill&) = delete; // Copy constructor
    Bill& operator=(const Bill&) = delete; // Copy assignment operator
    Bill(Bill&&) = default; // Move constructor
    Bill& operator=(Bill&&) = delete; // Move assignment operator
    ~Bill() = default; // Destructor

    Bill(float billamount, InvoiceRef inv);

    float billAmount() const { return _billAmount; }
    void setBillAmount(float billAmount) { _billAmount = billAmount; }

    InvoiceRef invoice() const { return _invoice; }
    void setInvoice(const InvoiceRef &invoice) { _invoice = invoice; }

    friend std::ostream &operator<<(std::ostream &os, const Bill &rhs);
};

#endif // BILL_H
