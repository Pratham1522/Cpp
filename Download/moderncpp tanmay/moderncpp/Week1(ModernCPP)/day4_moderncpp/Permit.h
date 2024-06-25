#ifndef PERMIT_H
#define PERMIT_H

#include <iostream>
#include "PermitType.h"
class Permit 
{
private:
    std::string _serial_number;
    PermitType  _permit_type;
    int _permit_duration_left;

public:
    Permit() = delete; // Default constructor
    Permit(const Permit&) = delete; // Copy constructor
    Permit& operator=(const Permit&) = delete; // Copy assignment operator
    Permit(Permit&&) = delete; // Move constructor
    Permit& operator=(Permit&&) = delete; // Move assignment operator
    ~Permit() = default; // Destructor

    Permit(std::string snumber,PermitType pType,int duration);

    std::string serialNumber() const { return _serial_number; }

    PermitType permitType() const { return _permit_type; }
    void setPermitType(const PermitType &permit_type) { _permit_type = permit_type; }

    int permitDurantLeft() const { return _permit_duration_left; }

    friend std::ostream &operator<<(std::ostream &os, const Permit &rhs);
};

#endif // PERMIT_H
