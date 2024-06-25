#include "Permit.h"

Permit::Permit(std::string number, int expiry_year)
    :_permit_number(number), _permit_expiry_year(expiry_year)
{
}

std::ostream &operator<<(std::ostream &os, const Permit &rhs) {
    os << "_permit_number: " << rhs._permit_number
       << " _permit_expiry_year: " << rhs._permit_expiry_year;
    return os;
}
