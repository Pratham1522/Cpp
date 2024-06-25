#include "TouristVehicle.h"




std::ostream &operator<<(std::ostream &os, const TouristVehicle &rhs) {
    os << "_number: " << rhs._number
       << " _seatCount: " << rhs._seatCount
       << " _perHourBookingCharge: " << rhs._perHourBookingCharge
       << " _permit: " << *rhs._permit;
    return os;
}

TouristVehicle::TouristVehicle(std::string number, Vehicle vehicle_type, unsigned int count, float charges, Permit *permit)
:_number(number), _type(vehicle_type), _seatCount(count), _perHourBookingCharge(charges), _permit(permit)
{
}

TouristVehicle::~TouristVehicle(){
    delete _permit;
}

/* 
modern cpp topics lval rval 
enum
nullptr
delete default
virtual pure virtual
*/