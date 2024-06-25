#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include <iostream>
#include<memory>
#include<variant>
#include<functional>
#include<list>
#include<vector>
#include "TouristVehicle.h"
#include "PrivateVehicle.h"

using VType = std::variant<std::shared_ptr<TouristVehicle>,std::shared_ptr<PrivateVehicle>>;
using Container = std::list<VType>;
using PermitContainer = std::vector<Permit>;

void CreateObjects(Container& data, PermitContainer& permits);
void Print(Container& data);

#endif // FUNCTIONALITIES_H
