#ifndef MAPFUNCTIONALITIES_H
#define MAPFUNCTIONALITIES_H

#include "TouristVehicle.h"
#include "Permit.h"
#include<list>
#include<optional>
#include<functional>
#include<memory>
#include<unordered_map>
#include<algorithm>

using TouristVehiclePtr = std::shared_ptr<TouristVehicle>;
using MapEntry = std::pair<std::string,TouristVehiclePtr>;
using PermitPointer = std::shared_ptr<Permit>;
using DataContainer = std::unordered_map<std::string,TouristVehiclePtr>;

/* 
populate map entries in the hash tables
 */
void CreateObjects(DataContainer& data);

/* 
first N instances satisfying conditions
-seat count >=4 & permittype :: lease
 */
std::optional<std::list<TouristVehiclePtr>> FindMatchingInstaces(const DataContainer& data,unsigned int N);

/* average per hour booking charge */
float AveragePerBookingCharges(const DataContainer& data);

/* max per hour booking charges */
float MaxPerBookingCharges(const DataContainer& data);

/* returns first N instances in a container */
std::list<TouristVehiclePtr> ReturnNInstances(const DataContainer& data, unsigned int N);

/* check if all instances have the same permitType */
bool AreContainerInstanceSamePermitType(const DataContainer& data);

/* return count of instances whose vehicle tpe is CAB */
std::size_t CountOfInstanceWithTypeCab(const DataContainer& data);

/* return permit ptr absed on id value */
std::optional<PermitPointer> FindPermitByID(const DataContainer& data,std::string id);

/* return maximum seat count from last N instances  */
int MaxSeatCount(const DataContainer& data,unsigned int N);

/* calculate gst on per hour booking charge based on a unary operator
passed by the user for all instances and  */
std::list<float> CalculateGstValues(DataContainer& data, 
std::function<float(const TouristVehiclePtr& ptr)> fn);


#endif // MAPFUNCTIONALITIES_H
