#include "CommercialOwner.h"

CommercialOwner::CommercialOwner(std::string name, std::string location, Vehicle *vehicle, long int gstnum)
    :Owner(name,location, vehicle)
{
    _gstNo = gstnum;
}

float CommercialOwner::PayRegisterationCharges()
{
    float charges = vehicle()->getPrice() * 0.2;
    return charges;
}

std::ostream &operator<<(std::ostream &os, const CommercialOwner &rhs) {
    os << static_cast<const Owner &>(rhs)
       << " _gstNo: " << rhs._gstNo
       << " _type: " << static_cast<int>(rhs._type);
    return os;
}
