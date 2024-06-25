#ifndef DEVICE_H
#define DEVICE_H

#include <iostream>
#include "DeviceType.h"
#include "Owner.h"
#include "License.h"

class Device 
{
private:
    std::string _deviceid{"0"};
    std::string _deviceName{""};
    float _price{0.0f};
    float _sarValue{0.0f};
    Devicetype _type{Devicetype::ACCESSORY};
    License *_license {nullptr};
    Owner *_owner {nullptr};    
public:
    Device() = default; // Default constructor
    Device(const Device&) = default; // Copy constructor
    Device& operator=(const Device&) = delete; // Copy assignment operator
    Device(Device&&) = delete; // Move constructor
    Device& operator=(Device&&) = delete; // Move assignment operator
    ~Device() = default; // Destructor

    Device(std::string id, std::string name, float price, float sarvalue, Devicetype type, License* lic, Owner* own);

    std::string deviceid() const { return _deviceid; }

    std::string deviceName() const { return _deviceName; }
    void setDeviceName(const std::string &deviceName) { _deviceName = deviceName; }

    float price() const { return _price; }

    float sarValue() const { return _sarValue; }

    Devicetype type() const { return _type; }
    void setType(const Devicetype &type) { _type = type; }

    License *license() const { return _license; }
    void setLicense(License *license) { _license = license; }

    Owner *owner() const { return _owner; }
    void setOwner(Owner *owner) { _owner = owner; }

    friend std::ostream &operator<<(std::ostream &os, const Device &rhs);
};

#endif // DEVICE_H
