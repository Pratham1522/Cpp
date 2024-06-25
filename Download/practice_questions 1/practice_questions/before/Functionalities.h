#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include<iostream>
#include "VectorEmptyException.h"
#include "Customer.h"
#include<vector>

using Container = std::vector<Customer*>;
/* 
FUNCTION to find customerid of the customer whose combined customertransactionamounts value is the highest
*/

void CreateObjects(Container &data);

unsigned int FindID(Container &data);

/* 
FUNCTION to find and return a container of customer objects whosecust type matches the type passed as the second parameter.
*/
Container FindInstanceOfSameType(Container &data, CustomerType type);

/* 
Function to return a container of all customer instances whose customerstorecreditsare between 100 and 200
*/
Container FindInstanceInSameRange(Container &data);

/* 
FUNCTION to find customer isntance with lowest and highest creits and print combined value for these credits
*/
void FindSumOfHigeshtAndLowest(Container &data);

/* 
    FUNCTION to find average of customerstorecredits with same type as second parameter
*/

void FindAverageOfSameType(Container &data, CustomerType type);

void DeleteObjects(Container &data);


#endif // FUNCTIONALITIES_H


