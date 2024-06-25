#include "Vehicle.h"

Vehicle::Vehicle(int id, std::string name, Type type, int price, unsigned int seatCount, std::string brand, FuelType fuelType, TransmissionType transmissionType)
    :_id(id), _name(name), _type(type), _price(price), _seatCount(seatCount), _brand(brand), _fuelType(fuelType), _transmissionType(transmissionType)
{
}
std::ostream &operator<<(std::ostream &os, const Vehicle &rhs) {
    os << "_id: " << rhs._id
       << " _name: " << rhs._name
       << " _type: ";
       if(static_cast<int>(rhs._type)==0){
        os<<"SUV";
       }
       else if(static_cast<int>(rhs._type)==1){
        os<<"HATCHBACK";
       }
       else{
        os<<"SEDAN";
       }
       os<< " _price: " << rhs._price
       << " _seatCount: " << rhs._seatCount
       << " _brand: " << rhs._brand
       << " _fuelType: ";
        if(static_cast<int>(rhs._fuelType)==0){
        os<<"PETROL";
       }
       else if(static_cast<int>(rhs._fuelType)==1){
        os<<"DIESEL";
       }
       else{
        os<<"CNG";
       }
       os<< " _transmissionType: ";
        if(static_cast<int>(rhs._transmissionType)==0){
        os<<"AUTOMATIC";
       }
       else if(static_cast<int>(rhs._transmissionType)==1){
        os<<"MANUAL";
       }
    return os;
}
