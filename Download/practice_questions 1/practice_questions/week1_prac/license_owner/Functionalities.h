#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include "Device.h"
#include<vector>

using Container = std::vector<Device*>;

void CreateOjects(Container &data);

void DeleteObjects(Container &data);

float CalculateDiscountPrice(Container &data, Devicetype type);

float CalculateTaxAmount(Container &data);

unsigned int CheckCondition(Container &data);

#endif // FUNCTIONALITIES_H
