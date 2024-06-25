#ifndef CARUNIT_H
#define CARUNIT_H
#include "CarType.h"
#include <iostream>

class CarUnit 
{
private:
    CarType _type{CarType::HATCHBACK};
    int _price{0};
    
public:
    CarUnit() = default; // Default constructor
    CarUnit(const CarUnit&) = default; // Copy constructor
    CarUnit& operator=(const CarUnit&) = delete; // Copy assignment operator
    CarUnit(CarUnit&&) = delete; // Move constructor
    CarUnit& operator=(CarUnit&&) = delete; // Move assignment operator
    ~CarUnit() = default; // Destructor

    CarUnit(CarType type, int price);

    CarType type() const { return _type; }
    void setType(const CarType &type) { _type = type; }

    int price() const { return _price; }
    void setPrice(int price) { _price = price; }
};

#endif // CARUNIT_H
