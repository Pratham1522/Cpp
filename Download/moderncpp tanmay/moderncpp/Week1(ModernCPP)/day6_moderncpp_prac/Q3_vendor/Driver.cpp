#include "Driver.h"

Driver::Driver(std::string name, long long number)
    :_driverName(name), _mobileNumber(number)
{
}
std::ostream &operator<<(std::ostream &os, const Driver &rhs) {
    os << "_driverName: " << rhs._driverName
       << " _mobileNumber: " << rhs._mobileNumber;
    return os;
}
