#ifndef CAR_H
#define CAR_H

#include <iostream>
#include "CarCategory.h"
#include "TyreSize.h"

class Car 
{
private:
    std::string _brandName;
    std::string _chassisNumber;
    CarCategory _type;
    int _tyrePressure;
    float _price;
public:
    Car() = default; // Default constructor
    Car(const Car&) = delete; // Copy constructor
    Car& operator=(const Car&) = delete; // Copy assignment operator
    Car(Car&&) = delete; // Move constructor
    Car& operator=(Car&&) = delete; // Move assignment operator
    ~Car() = default; // Destructor

    Car(std::string brandName,std::string chassisNumber,CarCategory type,int tyrePressure,float price);

    std::string brandName() const { return _brandName; }
    void setBrandName(const std::string &brandName) { _brandName = brandName; }

    std::string chassisNumber() const { return _chassisNumber; }
    void setChassisNumber(const std::string &chassisNumber) { _chassisNumber = chassisNumber; }

    CarCategory type() const { return _type; }
    void setType(const CarCategory &type) { _type = type; }

    int tyrePressure() const { return _tyrePressure; }
    void setTyrePressure(int tyrePressure) { _tyrePressure = tyrePressure; }

    float price() const { return _price; }
    void setPrice(float price) { _price = price; }

    friend std::ostream &operator<<(std::ostream &os, const Car &rhs);
};

#endif // CAR_H
