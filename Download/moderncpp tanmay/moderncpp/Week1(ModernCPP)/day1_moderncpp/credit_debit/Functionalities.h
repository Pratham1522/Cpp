#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H
#include "BankAccount.h"
#include "VectorEmptyException.h"
#include<vector>

using Container = std::vector<BankAccount*>;

void createObject(Container &data);

float calculateAverage(Container &data);

void Print(const Container &data);

#endif // FUNCTIONALITIES_H
