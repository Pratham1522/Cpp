#include "TouristVehicle.h"

TouristVehicle::~TouristVehicle()
{
    delete _permit;
}

TouristVehicle::TouristVehicle(std::string number, TouristVehicleType type, int count, float charges, Permit *p)
    :_number(number),_type(type),_seat_count(count), _per_hour_booking_charge(charges), _permit(p)
{
}

std::ostream &operator<<(std::ostream &os, const TouristVehicle &rhs) {
    os << "_number: " << rhs._number
       << " _type: " << static_cast<int>(rhs._type)
       << " _seat_count: " << rhs._seat_count
       << " _per_hour_booking_charge: " << rhs._per_hour_booking_charge
       << " _permit: " << rhs._permit;
    return os;
}
