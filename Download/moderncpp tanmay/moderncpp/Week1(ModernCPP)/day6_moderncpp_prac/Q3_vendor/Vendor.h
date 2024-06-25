#ifndef VENDOR_H
#define VENDOR_H
#include "Account.h"
#include <iostream>
#include "Customer.h"
#include "Driver.h"
#include "CarUnit.h"
#include<vector>

class Vendor : public Account
{
private:
    std::string _vendorName{""};    
    std::vector<Customer*>_customer{nullptr};
    std::vector<CarUnit*>_carunit{nullptr};
    std::vector<Driver*>_driver{nullptr};
public:
    Vendor() = default; // Default constructor
    Vendor(const Vendor&) = default; // Copy constructor
    Vendor& operator=(const Vendor&) = delete; // Copy assignment operator
    Vendor(Vendor&&) = delete; // Move constructor
    Vendor& operator=(Vendor&&) = delete; // Move assignment operator
    ~Vendor() = default; // Destructor

    Vendor(std::string name, std::vector<Customer*>customer,std::vector<Driver*>driver,std::vector<CarUnit*>carunit);


    std::string vendorName() const { return _vendorName; }
    void setVendorName(const std::string &vendorName) { _vendorName = vendorName; }

    std::vector<Customer*>customer() const { return _customer; }
    void setCustomer(const std::vector<Customer*>&customer) { _customer = customer; }

    std::vector<CarUnit*>carunit() const { return _carunit; }
    void setCarunit(const std::vector<CarUnit*>&carunit) { _carunit = carunit; }

    std::vector<Driver*>driver() const { return _driver; }
    void setDriver(const std::vector<Driver*>&driver) { _driver = driver; }
};

#endif // VENDOR_H