#include "Bill.h"

std::ostream &operator<<(std::ostream &os, const Bill &rhs) {
    os << "_billAmount: " << rhs._billAmount
       << " _invoice: " << rhs._invoice.get();
    return os;
}

Bill::Bill(float billamount, InvoiceRef inv)
    :_billAmount(billamount), _invoice(inv)
{
}
