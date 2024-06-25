#include "Ticket.h"

Ticket::Ticket(float tax)
    :_tax{tax}
{
}
std::ostream &operator<<(std::ostream &os, const Ticket &rhs) {
    os << "_tax: " << rhs._tax;
    return os;
}
