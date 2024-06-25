#ifndef PRIVATEVEHICLE_H
#define PRIVATEVEHICLE_H

#include <iostream>
#include "EngineType.h"

class PrivateVehicle 
{
private:
    std::string _registered_number {"0"};
    float _vehicle_price {0.0f};
    EngineType _engineType {EngineType::PETROL};
public:
    PrivateVehicle() = default; // Default constructor
    PrivateVehicle(const PrivateVehicle&) = default; // Copy constructor
    PrivateVehicle& operator=(const PrivateVehicle&) = delete; // Copy assignment operator
    PrivateVehicle(PrivateVehicle&&) = delete; // Move constructor
    PrivateVehicle& operator=(PrivateVehicle&&) = delete; // Move assignment operator
    ~PrivateVehicle() = default; // Destructor

    PrivateVehicle(std::string number, float price, EngineType type);

    float CalculateGST();

    std::string registeredNumber() const { return _registered_number; }

    float vehiclePrice() const { return _vehicle_price; }
    void setVehiclePrice(float vehicle_price) { _vehicle_price = vehicle_price; }

    EngineType engineType() const { return _engineType; }
    void setEngineType(const EngineType &engineType) { _engineType = engineType; }

    friend std::ostream &operator<<(std::ostream &os, const PrivateVehicle &rhs);
};

#endif // PRIVATEVEHICLE_H
