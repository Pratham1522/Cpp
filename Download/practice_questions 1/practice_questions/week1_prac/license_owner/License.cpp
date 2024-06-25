#include "License.h"

License::License(int number, LicenseType type)
    :_licenseNumber(number), _type(type)
{
}
std::ostream &operator<<(std::ostream &os, const License &rhs) {
    os << "_licenseNumber: " << rhs._licenseNumber
       << " _type: " <<static_cast<int>(rhs._type);
    return os;
}
