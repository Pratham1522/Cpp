#include "Permit.h"

Permit::Permit(std::string snumber, PermitType pType, int duration)
    :_serial_number(snumber), _permit_type(pType), _permit_duration_left(duration)
{
}
std::ostream &operator<<(std::ostream &os, const Permit &rhs) {
    os << "_serial_number: " << rhs._serial_number
       << " _permit_type: ";
        if(static_cast<int>(rhs._permit_type)==0){
            os<<"LEASE";
        }
        else{
            os<<"OWN";
        }

       os<< " _permit_durant_left: " << rhs._permit_duration_left;
    return os;
}
