#include "Owner.h"


Owner::Owner(std::string name, std::string location, Vehicle *vehicle)
    : _name(name), _location(location), _vehicle(vehicle)
{
}

std::ostream &operator<<(std::ostream &os, const Owner &rhs) {
    os << "_name: " << rhs._name
       << " _location: " << rhs._location
       << " _vehicle: " << *rhs._vehicle;
    return os;
}
