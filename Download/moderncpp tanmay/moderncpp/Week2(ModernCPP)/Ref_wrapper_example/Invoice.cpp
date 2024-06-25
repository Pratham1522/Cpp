#include "Invoice.h"

Invoice::Invoice(std::string number, InvoiceType type, int items)
    :_invoicenumber(number), _type(type), _items(items)
{
}
std::ostream &operator<<(std::ostream &os, const Invoice &rhs) {
    os << "_invoicenumber: " << rhs._invoicenumber
       << " _type: " << static_cast<int>(rhs._type)
       << " _items: " << rhs._items;
    return os;
}
