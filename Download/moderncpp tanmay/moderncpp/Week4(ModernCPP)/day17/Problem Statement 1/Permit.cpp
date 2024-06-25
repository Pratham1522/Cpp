#include "Permit.h"

Permit::Permit(std::string snumber, PermitType pType, int duration_left)
        : _serial_number{snumber}, _permit_type{pType}, _permit_duration_left{duration_left} 
{

}

std::ostream &operator<<(std::ostream &os, const Permit &rhs) 
{
    os << "_serial_number: " << rhs._serial_number
       << " _permit_type: ";

       std::string val{""};

       if(rhs._permit_type == PermitType::LEASE)
        {
            val = "LEASE";
        }
       else
        {
            val = "OWNED";
        }
       
       os << val << " _permit_duration_left: " << rhs._permit_duration_left;
    return os;
}
