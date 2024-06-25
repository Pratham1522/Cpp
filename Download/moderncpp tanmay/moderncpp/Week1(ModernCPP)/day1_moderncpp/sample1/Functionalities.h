#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include<vector>
#include "BankAccount.h"

using Container = std::vector<BankAccount*>;

void CreateObjects(Container& data);

float AverageAccountBalance(Container& data);

void deleteobjects(Container &data);

#endif // FUNCTIONALITIES_H
