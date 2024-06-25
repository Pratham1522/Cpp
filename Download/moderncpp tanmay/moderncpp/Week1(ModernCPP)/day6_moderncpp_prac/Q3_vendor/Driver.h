#ifndef DRIVER_H
#define DRIVER_H

#include <iostream>

class Driver 
{
private:
    std::string _driverName{""};
    long long _mobileNumber{0000000000};

public:
    Driver() = default; // Default constructor
    Driver(const Driver&) = default; // Copy constructor
    Driver& operator=(const Driver&) = delete; // Copy assignment operator
    Driver(Driver&&) = delete; // Move constructor
    Driver& operator=(Driver&&) = delete; // Move assignment operator
    ~Driver() = default; // Destructor

    Driver(std::string name, long long number);

    std::string driverName() const { return _driverName; }
    void setDriverName(const std::string &driverName) { _driverName = driverName; }

    long long mobileNumber() const { return _mobileNumber; }
    void setMobileNumber(long long mobileNumber) { _mobileNumber = mobileNumber; }

    friend std::ostream &operator<<(std::ostream &os, const Driver &rhs);
};

#endif // DRIVER_H
