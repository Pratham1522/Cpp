#include "Device.h"

Device::Device(std::string id, std::string name, float price, float sarvalue, Devicetype type, License *lic, Owner *own)
    :_deviceid(id), _deviceName(name), _price(price), _sarValue(sarvalue), _type(type), _license(lic), _owner(own)
{
}
std::ostream &operator<<(std::ostream &os, const Device &rhs) {
    os << "_deviceid: " << rhs._deviceid
       << " _deviceName: " << rhs._deviceName
       << " _price: " << rhs._price
       << " _sarValue: " << rhs._sarValue
       << " _type: " << static_cast<int>(rhs._type)
       << " _license: " << *rhs._license
       << " _owner: " << *rhs._owner;
    return os;
}
