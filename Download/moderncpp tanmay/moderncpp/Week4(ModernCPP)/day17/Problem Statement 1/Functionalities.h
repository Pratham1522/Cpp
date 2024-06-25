#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include <vector>
#include <memory>
#include <unordered_map>
#include <future>
#include <list>
#include "TouristVehicle.h"
#include "Permit.h"
#include "EmptyContainerException.h"
#include "NoInstanceException.h"
#include "InvalidInputException.h"
#include "ConditionDoesNotMatchException.h"

using Shared_Tourist = std::shared_ptr<TouristVehicle>;
using Container = std::unordered_map<std::string, Shared_Tourist>;

/*
    <------------------------------------------------OBJECT DIAGRAM------------------------------------------------>

    Key: "t101"

    Value [ BUCKET 1 ]:
                            [ pr101" | LEASE | 12 ]
                                |
                                |
                                |
    [ "t101" | CAB | 4 | 500 | 1x800H ]
*/

void CreateObjects(Container &data);


// Average price for a given type
float AverageBookingChargeForGivenType(Container& data, TouristVehicleType& type);

// ID of max charge of instance
std::string FindMaxChargeId(const Container& data);

// Find First N Instances
// std::list<Shared_Tourist> FindFirstNInstance(Container& data, std::future<unsigned int>& N);
std::list<Shared_Tourist> FindFirstNInstance(Container& data, std::future<unsigned int>& N);



#endif // FUNCTIONALITIES_H
