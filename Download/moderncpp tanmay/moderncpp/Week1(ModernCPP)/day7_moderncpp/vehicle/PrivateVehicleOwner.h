#ifndef PRIVATEVEHICLEOWNER_H
#define PRIVATEVEHICLEOWNER_H

#include <iostream>
#include "Owner.h"

class PrivateVehicleOwner : public Owner
{
private:
    long int _aadharNo{000000000000};

public:
    PrivateVehicleOwner() = default; // Default constructor
    PrivateVehicleOwner(const PrivateVehicleOwner&) = default; // Copy constructor
    PrivateVehicleOwner& operator=(const PrivateVehicleOwner&) = delete; // Copy assignment operator
    PrivateVehicleOwner(PrivateVehicleOwner&&) = delete; // Move constructor
    PrivateVehicleOwner& operator=(PrivateVehicleOwner&&) = delete; // Move assignment operator
    ~PrivateVehicleOwner() = default; // Destructor

    PrivateVehicleOwner(std::string name, std::string location, Vehicle* vehicle,long int number);

    float PayRegisterationCharges();

    long int aadharNo() const { return _aadharNo; }

    friend std::ostream &operator<<(std::ostream &os, const PrivateVehicleOwner &rhs);
};

#endif // PRIVATEVEHICLEOWNER_H
