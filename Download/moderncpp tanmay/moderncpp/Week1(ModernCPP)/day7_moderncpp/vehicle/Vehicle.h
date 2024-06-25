#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>
#include "Type.h"
#include "TransmissionType.h"
#include "FuelType.h"

class Vehicle 
{
private:
    int _id{0};
    std::string _name{""};
    Type _type{Type::HATCHBACK};
    int _price{0};
    unsigned int _seatCount{0};
    std::string _brand{""};
    FuelType _fuelType{FuelType::PETROL};
    TransmissionType _transmissionType{TransmissionType::AUTOMATIC};
    
public:
    Vehicle() = default; // Default constructor
    Vehicle(const Vehicle&) = default; // Copy constructor
    Vehicle& operator=(const Vehicle&) = delete; // Copy assignment operator
    Vehicle(Vehicle&&) = delete; // Move constructor
    Vehicle& operator=(Vehicle&&) = delete; // Move assignment operator
    ~Vehicle() = default; // Destructor

    Vehicle(int id,
std::string name,
Type type,
int price,
unsigned int seatCount,
std::string brand,
FuelType fuelType,
TransmissionType transmissionType);

    std::string name() const { return _name; }
    void setName(const std::string &name) { _name = name; }


    int getPrice() const { return _price; }

    unsigned int seatCount() const { return _seatCount; }

    std::string getBrand() const { return _brand; }

    TransmissionType transmissionType() const { return _transmissionType; }
    void setTransmissionType(const TransmissionType &transmissionType) { _transmissionType = transmissionType; }

    FuelType fuelType() const { return _fuelType; }
    void setFuelType(const FuelType &fuelType) { _fuelType = fuelType; }

    Type type() const { return _type; }
    void setType(const Type &type) { _type = type; }

    int id() const { return _id; }
    void setId(int id) { _id = id; }

    friend std::ostream &operator<<(std::ostream &os, const Vehicle &rhs);

};

#endif // VEHICLE_H
