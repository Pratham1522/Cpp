#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H
#include "TouristVehicle.h"
#include<iostream>
#include<list>
#include<vector>

using Container = std::list<TouristVehicle*>;

void createObject(Container &data);

std::vector<TouristVehicle*> find(Container &data);

void findaverage(Container &data);

void findmaximum(Container &data);

void DeleteObjects(Container &data);


#endif // FUNCTIONALITIES_H
