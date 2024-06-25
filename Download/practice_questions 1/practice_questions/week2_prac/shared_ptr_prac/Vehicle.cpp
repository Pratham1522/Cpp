#include "Vehicle.h"

Vehicle::Vehicle(int id, std::string name)
    :_id(id),_carname(name)
{
}
std::ostream &operator<<(std::ostream &os, const Vehicle &rhs) {
    os << "_id: " << rhs._id
       << " _carname: " << rhs._carname;
    return os;
}
