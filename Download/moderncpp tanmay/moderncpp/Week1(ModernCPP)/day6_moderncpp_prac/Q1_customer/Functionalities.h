#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H
#include"Customer.h"
#include<iostream>
#include<vector>

using Container = std::vector<Customer*>;

void createObjects(Container &data);

int FindCustomerIDByMaxTransactionAmount(Container &data);

Container FindContainerOfSameType(Container &data, CustomerType type);

Container FindInstancesinSameRange(Container &data);

void FindInstanceOfHighestnLowest(Container &data);

double FindAverageOfSameType(Container &data, CustomerType type);

bool FindIfAllTypeAreSame(Container &data);


#endif // FUNCTIONALITIES_H
