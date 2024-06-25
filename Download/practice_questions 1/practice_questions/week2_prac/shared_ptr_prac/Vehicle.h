#ifndef VEHICLE_H
#define VEHICLE_H

#include <iostream>

class Vehicle 
{
private:
    int _id{0};
    std::string _carname{""};
public:
    Vehicle() = default; // Default constructor
    Vehicle(const Vehicle&) = default; // Copy constructor
    Vehicle& operator=(const Vehicle&) = delete; // Copy assignment operator
    Vehicle(Vehicle&&) = delete; // Move constructor
    Vehicle& operator=(Vehicle&&) = delete; // Move assignment operator
    ~Vehicle() = default; // Destructor

    Vehicle(int id, std::string name);

    friend std::ostream &operator<<(std::ostream &os, const Vehicle &rhs);
};

#endif // VEHICLE_H
