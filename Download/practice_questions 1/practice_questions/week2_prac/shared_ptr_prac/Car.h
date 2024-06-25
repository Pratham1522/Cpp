#ifndef CAR_H
#define CAR_H

#include <iostream>
#include<memory>
#include "Vehicle.h"

class Car 
{
private:
    int _num{0};
    std::shared_ptr<Vehicle> _sptr{nullptr};
public:
    Car() = default; // Default constructor
    Car(const Car&) = default; // Copy constructor
    Car& operator=(const Car&) = delete; // Copy assignment operator
    Car(Car&&) = default; // Move constructor
    Car& operator=(Car&&) = delete; // Move assignment operator
    ~Car() = default; // Destructor

    Car(int num,std::shared_ptr<Vehicle> sptr);

    friend std::ostream &operator<<(std::ostream &os, const Car &rhs);
};

#endif // CAR_H
