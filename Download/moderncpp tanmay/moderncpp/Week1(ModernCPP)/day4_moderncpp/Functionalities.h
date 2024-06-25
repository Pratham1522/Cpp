#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include<vector>
#include "TouristVehicle.h"
#include "Permit.h"

using Container = std::vector<TouristVehicle*>;

/* always make a sample object
["mh1276"]|cab|4|500 | 0x100H
                           | 
                        ["p101"|LEASE|10] 

 */
//create instance method
void CreateObjects(Container& data);

//return n instances
Container FirstNMatchingInstance(const Container& data,const unsigned int n);
//average for given type
float AverageBookingChargeForGivenType(const Container& data, TouristVehicleType type);
//id of max charge isntance
std::string FindMaxChargeId(const Container& data);

//return first n isntances with no condition

Container FindFirstNInstances(const Container& data,const unsigned int n);

void DeleteObjects(Container& data);

#endif // FUNCTIONALITIES_H
