#ifndef COMMERCIALOWNER_H
#define COMMERCIALOWNER_H

#include <iostream>
#include "Owner.h"
#include "CommercialOwnerType.h"

class CommercialOwner : public Owner
{
private:
    long int _gstNo{00000000};
    CommercialOwnerType _type;
    
    
public:
    CommercialOwner() = default; // Default constructor
    CommercialOwner(const CommercialOwner&) = default; // Copy constructor
    CommercialOwner& operator=(const CommercialOwner&) = delete; // Copy assignment operator
    CommercialOwner(CommercialOwner&&) = delete; // Move constructor
    CommercialOwner& operator=(CommercialOwner&&) = delete; // Move assignment operator
    ~CommercialOwner() = default; // Destructor

    CommercialOwner(std::string name, std::string location, Vehicle* vehicle, long int gstnum);

    float PayRegisterationCharges();

    CommercialOwnerType type() const { return _type; }
    void setType(const CommercialOwnerType &type) { _type = type; }

    friend std::ostream &operator<<(std::ostream &os, const CommercialOwner &rhs);
};

#endif // COMMERCIALOWNER_H
