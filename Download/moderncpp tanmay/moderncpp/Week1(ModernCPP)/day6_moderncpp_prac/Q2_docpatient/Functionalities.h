#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H
#include<iostream>
#include "Doctor.h"
#include<vector>

using Container = std::vector<Doctor*>;

void CreateObjects(Container &data);

int CountOfValAbove5000(Container &data);

void CheckCardiologistAvailability(Container &data);

double CheckAverageOfPatient(Container &data);

void Display(Container &data, int n);

void deleteobjects(Container &data);

#endif // FUNCTIONALITIES_H

