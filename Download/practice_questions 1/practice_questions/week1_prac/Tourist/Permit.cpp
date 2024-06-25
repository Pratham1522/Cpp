#include "Permit.h"

Permit::Permit(std::string serialnum, Own type, int duration)
    :_serialNumber(serialnum), _permitType(type), _permitDuration(duration)
{
}
std::ostream &operator<<(std::ostream &os, const Permit &rhs) {
    os << "_serialNumber: " << rhs._serialNumber
       << " _permitType: " << static_cast<int>(rhs._permitType)
       << " _permitDuration: " << rhs._permitDuration;
    return os;
}

std::ostream &operator<<(std::ostream &os, const sample &rhs)
{
    os <<"integer st is: "<<rhs.st;
    return os;
}
