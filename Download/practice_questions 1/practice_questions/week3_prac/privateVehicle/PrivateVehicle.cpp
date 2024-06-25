#include "PrivateVehicle.h"

PrivateVehicle::PrivateVehicle(std::string number, float price, EngineType type)
    :_registered_number{number}, _vehicle_price{price}, _engineType{type}
{
}

float PrivateVehicle::CalculateGST()
{
    return _vehicle_price/20.0f;
}

std::ostream &operator<<(std::ostream &os, const PrivateVehicle &rhs) {
    os << "_registered_number: " << rhs._registered_number
       << " _vehicle_price: " << rhs._vehicle_price
       << " _engineType: ";
       if(static_cast<int>(rhs._engineType)==0){
        os<<"PETROL";
       }
       else if(static_cast<int>(rhs._engineType)==1){
        os<<"DIESEL";
       }
       else{
        os<<"HYBRID";
       }
    return os;
}
