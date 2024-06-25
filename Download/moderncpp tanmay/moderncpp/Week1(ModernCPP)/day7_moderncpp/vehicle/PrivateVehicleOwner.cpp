#include "PrivateVehicleOwner.h"

PrivateVehicleOwner::PrivateVehicleOwner(std::string name, std::string location, Vehicle* vehicle,long int number)
    :Owner(name,location,vehicle)
{
    _aadharNo = number;
}

float PrivateVehicleOwner::PayRegisterationCharges()
{
    float charges = vehicle()->getPrice() * 0.1;
    return charges;
}

std::ostream &operator<<(std::ostream &os, const PrivateVehicleOwner &rhs) {
    os << static_cast<const Owner &>(rhs)
       << " _aadharNo: " << rhs._aadharNo;
    return os;
}
