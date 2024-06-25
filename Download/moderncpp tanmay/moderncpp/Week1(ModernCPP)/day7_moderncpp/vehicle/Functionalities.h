#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include "PrivateVehicleOwner.h"
#include "CommercialOwner.h"

#include<vector>

using Container = std::vector<Owner*>;

void CreateObjects(Container &data);

void DeleteObjects(Container &data);

void FindVehicleOnID(Container &data, int id);

void FindMinimum_Average_Maximum(Container &data);

void FindVehicleDetailsOnType(Container &data, Type type);

Container FindLastNInstance(Container &data, int n);

void FindInstacesOverThreshold(Container &data);

void FindDetailsOfCommercialOwner(Container &data);

void Print(Container &data);


#endif // FUNCTIONALITIES_H


/* 
    smart pointers, shared pointers, 
*/