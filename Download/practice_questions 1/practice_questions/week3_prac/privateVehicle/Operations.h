#ifndef OPERATIONS_H
#define OPERATIONS_H

#include <iostream>
#include<memory>
#include<variant>
#include<functional>
#include<list>
#include<vector>
#include "TouristVehicle.h"
#include "PrivateVehicle.h"
#include<thread>
#include<future>

using VType = std::variant<std::shared_ptr<TouristVehicle>,std::shared_ptr<PrivateVehicle>>;
using Container = std::list<VType>;
using PrivateContainer = std::vector<std::shared_ptr<PrivateContainer>>;
using PermitContainer = std::vector<Permit>;


class Operations 
{
private:
    int m_value{0};
    Container data;
    PermitContainer permits;

    static Operations *instance;
    Operations() = default; // Default constructor
    Operations(const Operations&) = default; // Copy constructor
    Operations& operator=(const Operations&) = delete; // Copy assignment operator
    Operations(Operations&&) = delete; // Move constructor
    Operations& operator=(Operations&&) = delete; // Move assignment operator
public:
    ~Operations() = default; // Destructor
    static Operations *getInstance();
    void CreateObjects();
    void Print();
    void ReturnAverage();
    float ReturnTrueIfAllPriceAbove5L();

    std::optional<PrivateContainer> FetchPrivateVehiclePointer();
};

#endif // OPERATIONS_H
