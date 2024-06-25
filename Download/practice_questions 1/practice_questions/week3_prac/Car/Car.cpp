#include "Car.h"

Car::Car(std::string brandName, std::string chassisNumber, CarCategory type, int tyrePressure, float price)
    :_brandName(brandName), _chassisNumber{chassisNumber}, _type{type}, _tyrePressure{tyrePressure}, _price{price}
{
}
std::ostream &operator<<(std::ostream &os, const Car &rhs) {
    os << "_brandName: " << rhs._brandName
       << " _chassisNumber: " << rhs._chassisNumber
       << " _type: "<<(static_cast<int>(rhs._type))
       << " _tyrePressure: " << rhs._tyrePressure
       << " _price: " << rhs._price;
    return os;
}
