#ifndef LICENSE_H
#define LICENSE_H

#include <iostream>
#include "LicenseType.h"

class License 
{
private:
    int _licenseNumber{0};
    LicenseType _type{LicenseType::RENTED};    

public:
    License() = default; // Default constructor
    License(const License&) = default; // Copy constructor
    License& operator=(const License&) = delete; // Copy assignment operator
    License(License&&) = delete; // Move constructor
    License& operator=(License&&) = delete; // Move assignment operator
    ~License() = default; // Destructor

    License(int number, LicenseType type);

    LicenseType type() const { return _type; }
    void setType(const LicenseType &type) { _type = type; }

    friend std::ostream &operator<<(std::ostream &os, const License &rhs);
};

#endif // LICENSE_H
