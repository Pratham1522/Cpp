#include "Functionalities.h"
#include <iostream>

void CreateObjects(Container &data)
{
    data.emplace
    (
        std::make_pair<std::string, std::shared_ptr<TouristVehicle>>
        (
            "t101",
            std::make_shared<TouristVehicle>
            (
                "t101", TouristVehicleType::CAB, 4, 500, 
                std::make_shared<Permit>
                (
                    "p101", PermitType::LEASE, 12
                )
            )
        )
    );

    data.emplace
    (
        std::make_pair<std::string, std::shared_ptr<TouristVehicle>>
        (
            "mh101",
            std::make_shared<TouristVehicle>
            (
                "mh101", TouristVehicleType::BIKE, 2, 250, 
                std::make_shared<Permit>
                (
                    "h201", PermitType::OWNED, 12
                )
            )
        )
    );
}


float AverageBookingChargeForGivenType(Container &data, TouristVehicleType& type)
{
    if(data.empty())
    {
        throw EmptyContainerException("Data container is empty", std::future_errc::no_state);
    }
    
    float total = {0.0f};
    unsigned int count = 0;

    for(const std::pair<std::string, Shared_Tourist>& p : data)
    {
        if(p.second && p.second->type() == type)
        {
            total += p.second->perHourBookingCharge();
            count++;
        }
    }

    if(count == 0)
    {
        throw NoInstanceException("No instance of given type exists", std::future_errc::no_state);
    }

    return total/(float)count;
}


std::string FindMaxChargeId(const Container &data)
{
    if(data.empty())
    {
        throw EmptyContainerException("Max cannot be calculated", std::future_errc::no_state);
    }

    // std::string id = data.at("t101")->permit()->serialNumber();

    // float max = data.at("t101") -> perHourBookingCharge();
    
    std::string id = data.begin()->second->permit()->serialNumber();

    float max = data.begin()->second->perHourBookingCharge();

    for(auto&[k,v] : data)
    {
        if(v)
        {
            if(v && v->perHourBookingCharge() > max)
            {
                max = v->perHourBookingCharge();
                id = v->permit()->serialNumber();
            }
        }
    }
    
    return id;
}

std::list<Shared_Tourist> FindFirstNInstance(Container &data, std::future<unsigned int>& N)
{
    unsigned int n1 = N.get();
    
    if(data.empty())
    {
        throw EmptyContainerException("N Instances cannot be found", std::future_errc::no_state);
    }

    if(n1 < 0 || n1>data.size())
    {
        throw InvalidInputException("N is invalid", std::future_errc::no_state);
    }

    std::list<Shared_Tourist> result;

    for(auto&[k,v] : data)
    {
        if(v && v->seatCount() >= 4 && v->permit() -> permitType() == PermitType::LEASE)
        {
            result.push_back(v);

            if(result.size() == n1)
            {
                break;
            }
        }
    }

    if(result.empty())
    {
        throw NoInstanceException("None of the objects satisfy the condition", std::future_errc::no_state);
    }    

    if(result.size() < n1)
    {
        throw ConditionDoesNotMatchException("I didn't find N instances maybe less than that", std::future_errc::no_state);
    }

    return result;
}
