#ifndef TOURISTVEHICLE_H
#define TOURISTVEHICLE_H

#include <iostream>
#include "VehicleType.h"
#include<functional>
#include "Permit.h"

using PermitWrapper = std::reference_wrapper<Permit>;

class TouristVehicle 
{
private:
    std::string _registered_number {"0"};
    float _vehicle_price {0.0f};
    VehicleType _type {VehicleType::CAB};
    PermitWrapper _permit;

public:
    TouristVehicle() = default; // Default constructor
    TouristVehicle(const TouristVehicle&) = default; // Copy constructor
    TouristVehicle& operator=(const TouristVehicle&) = delete; // Copy assignment operator
    TouristVehicle(TouristVehicle&&) = default; // Move constructor
    TouristVehicle& operator=(TouristVehicle&&) = delete; // Move assignment operator
    ~TouristVehicle() = default; // Destructor

    TouristVehicle(std::string number, float price, VehicleType type, PermitWrapper permit);

    float CalculatePermitRenewalCost();

    std::string registeredNumber() const { return _registered_number; }

    float vehiclePrice() const { return _vehicle_price; }
    void setVehiclePrice(float vehicle_price) { _vehicle_price = vehicle_price; }

    VehicleType type() const { return _type; }
    void setType(const VehicleType &type) { _type = type; }

    PermitWrapper permit() const { return _permit; }
    void setPermit(const PermitWrapper &permit) { _permit = permit; }

    friend std::ostream &operator<<(std::ostream &os, const TouristVehicle &rhs);
};

#endif // TOURISTVEHICLE_H
