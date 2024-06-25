#include "TouristVehicle.h"

std::ostream &operator<<(std::ostream &os, const TouristVehicle &rhs) 
{
    os << "_number: " << rhs._number
       << " _type: ";
       
       std::string val{""};

       if(rhs._type == TouristVehicleType::BIKE) { val = "BIKE"; }
       else if(rhs._type == TouristVehicleType::CAB) { val = "CAB"; }
       else { val = "BUS"; }

       os << val
       
       << " _seat_count: " << rhs._seat_count
       << " _per_hour_booking_charge: " << rhs._per_hour_booking_charge
       << " _permit: " << *rhs._permit;
    return os;
}

TouristVehicle::TouristVehicle(std::string number, TouristVehicleType type, int count, float charges, std::shared_ptr<Permit> _permit)
                : _number{number}, _type{type}, _seat_count{count}, _per_hour_booking_charge{charges}, _permit{_permit}
{
}
