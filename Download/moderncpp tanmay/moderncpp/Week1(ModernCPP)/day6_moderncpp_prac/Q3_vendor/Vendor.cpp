#include "Vendor.h"

Vendor::Vendor(std::string name, std::vector<Customer *> customer, std::vector<Driver *> driver, std::vector<CarUnit *> carunit)
    :_vendorName(name), _customer(customer), _driver(driver), _carunit(carunit)
{
}
