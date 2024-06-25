#ifndef OWNER_H
#define OWNER_H

#include <iostream>
#include "Vehicle.h"

class Owner 
{
private:    
    std::string _name{""};
    std::string _location{""};
    Vehicle* _vehicle{nullptr};
public:
    Owner() = default; // Default constructor
    Owner(const Owner&) = default; // Copy constructor
    Owner& operator=(const Owner&) = delete; // Copy assignment operator
    Owner(Owner&&) = default; // Move constructor
    Owner& operator=(Owner&&) = delete; // Move assignment operator
    ~Owner() = default; // Destructor

    Owner(std::string name, std::string location, Vehicle* vehicle);

    virtual float PayRegisterationCharges()=0; //make function abstract to calculate differntly in child classes.

    Vehicle* vehicle() const { return _vehicle; }
    void setVehicle(Vehicle* vehicle) { _vehicle = vehicle; }


    friend std::ostream &operator<<(std::ostream &os, const Owner &rhs);
};

#endif // OWNER_H
