#ifndef OPERATIONS_H
#define OPERATIONS_H

#include <iostream>
#include "Car.h"
#include<functional>
#include<vector>
#include<optional>
#include<memory>

using CarPtr = std::shared_ptr<Car>;
using Container = std::vector<CarPtr>;

class Operations 
{
private:
    static std::shared_ptr<Operations>(instance); 
    Container data;

public:
    Operations() = default; // Default constructor
    Operations(const Operations&) = delete; // Copy constructor
    Operations& operator=(const Operations&) = delete; // Copy assignment operator
    Operations(Operations&&) = delete; // Move constructor
    Operations& operator=(Operations&&) = delete; // Move assignment operator
    ~Operations() = default; // Destructor

    static std::shared_ptr<Operations> getInstance();

    void CreateObject();
    std::optional<Container> ReturnThoseCarsThatHavePriceMoreThanThreshold(float threshold);
    Container ReturnCarWithSameChassisNumber(std::string chassisnum);
    Container ReturnCarWithSameCarType(CarCategory type);
};

#endif // OPERATIONS_H
