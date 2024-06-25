#ifndef INVOICE_H
#define INVOICE_H

#include <iostream>
#include "InvoiceType.h"

class Invoice 
{
private:
    std::string _invoicenumber{"0"};
    InvoiceType _type{InvoiceType::EBILL};
    int _items;

public:
    Invoice() = default; // Default constructor
    Invoice(const Invoice&) = delete; // Copy constructor
    Invoice& operator=(const Invoice&) = delete; // Copy assignment operator
    Invoice(Invoice&&) = default; // Move constructor
    Invoice& operator=(Invoice&&) = delete; // Move assignment operator
    ~Invoice() = default; // Destructor

    Invoice(std::string number, InvoiceType type, int items);

    std::string invoicenumber() const { return _invoicenumber; }

    InvoiceType type() const { return _type; }
    void setType(const InvoiceType &type) { _type = type; }

    int items() const { return _items; }

    friend std::ostream &operator<<(std::ostream &os, const Invoice &rhs);
};

#endif // INVOICE_H
