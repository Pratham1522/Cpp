#ifndef PERMIT_H
#define PERMIT_H

#include <iostream>
#include "InvalidExipryYearException.h"

class Permit 
{
private:
    std::string _permit_number {"0"};
    int _permit_expiry_year {2024};
public:
    Permit() = default; // Default constructor
    Permit(const Permit&) = default; // Copy constructor
    Permit& operator=(const Permit&) = delete; // Copy assignment operator
    Permit(Permit&&) = default; // Move constructor
    Permit& operator=(Permit&&) = delete; // Move assignment operator
    ~Permit() = default; // Destructor

    Permit(std::string number, int expiry_year);

    std::string permitNumber() const { return _permit_number; }

    int permitExpiryYear() const { return _permit_expiry_year; }
    void setPermitExpiryYear(int permit_expiry_year) { _permit_expiry_year = permit_expiry_year; }

    friend std::ostream &operator<<(std::ostream &os, const Permit &rhs);
};

#endif // PERMIT_H
