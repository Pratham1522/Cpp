#include "TouristVehicle.h"

TouristVehicle::TouristVehicle(std::string number, float price, VehicleType type, PermitWrapper permit)
    :_registered_number{number}, _vehicle_price{price}, _type{type}, _permit{permit}
{
}
float TouristVehicle::CalculatePermitRenewalCost()
{
    if(_type==VehicleType::CAB || _type==VehicleType::BUS){
        return _vehicle_price*0.15f;
    }
    else if(_type==VehicleType::OTHER){
        return _vehicle_price*0.1f;
    }
    return 0.0f;
}

std::ostream &operator<<(std::ostream &os, const TouristVehicle &rhs)
{
    os << "_registered_number: " << rhs._registered_number
       << " _vehicle_price: " << rhs._vehicle_price
       << " _type: ";
        if(static_cast<int>(rhs._type)==0){
            os<<"CAB";
        }
        else if(static_cast<int>(rhs._type)==1){
            os<<"BUS";
        }
        else{
            os<<"OTHER";
        }
       os<< " _permit: " << rhs._permit.get();
    return os;
}
