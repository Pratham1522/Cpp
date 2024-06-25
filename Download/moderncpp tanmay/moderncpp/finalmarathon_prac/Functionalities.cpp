#include "Functionalities.h"
#include<algorithm>
#include<numeric>

void CreateObjects(DataContainer &data)
{
    data.emplace_back(
        std::make_shared<TouristVehicle>("1",TouristVehicleType::CAB,4,1000.0f,
        std::make_shared<Permit>("P1",PermitType::LEASE,5))
    );
    data.emplace_back(
        std::make_shared<TouristVehicle>("2",TouristVehicleType::BIKE,6,2000.0f,
        std::make_shared<Permit>("P2",PermitType::LEASE,4))
    );
    data.emplace_back(
        std::make_shared<TouristVehicle>("3",TouristVehicleType::BUS,3,3000.0f,
        std::make_shared<Permit>("P3",PermitType::OWNED,8))
    );
    data.emplace_back(
        std::make_shared<TouristVehicle>("4",TouristVehicleType::CAB,5,4000.0f,
        std::make_shared<Permit>("P4",PermitType::OWNED,11))
    );
    data.emplace_back(
        std::make_shared<TouristVehicle>("5",TouristVehicleType::CAB,4,5000.0f,
        std::make_shared<Permit>("P5",PermitType::LEASE,3))
    );
}

/* 
a) matching condition instances have to be copied
b) if N or more wiere instances were copied, we can now return first n isntanve from
 this copied collection to the user
    obj1        obj2        obj3        obj4        obj5
    2 instances matching condition
    obj1,obj4,obj5 satisfy. return first 2 instances.
 */
std::optional<DataContainer> FindMatchingInstaces(const DataContainer &data, unsigned int N)
{
    if(data.empty()){
        throw std::runtime_error("data is empty");
    }
    DataContainer result;
    std::copy_if(data.begin(),data.end(),std::inserter(result,result.begin()),
    [](const TouristVehiclePointer& t){
        return (t->seatCount()>=4 && t->permit()->permitType()==PermitType::LEASE);
    });
    result.resize(N);
    if(result.empty()){
        return std::nullopt;
    }
    return result;
    // DataContainer finalanswer;
    // std::copy_n(result.begin(),N,std::inserter(finalanswer,finalanswer.begin()));
    // return finalanswer;
}

float AveragePerBookingCharges(const DataContainer &data)
{
    if(data.empty()){
        throw std::runtime_error("data is empty");
    }
    float total = std::accumulate(data.begin(),data.end(),
    0.0f,
    [](float answer_upto_curr,const TouristVehiclePointer& ptr){
        return answer_upto_curr + ptr->perHourBookingCharge();
    });
    return total/data.size();
}

float MaxPerBookingCharges(const DataContainer &data)
{
    if(data.empty()){
        throw std::runtime_error("data is empty");
    }

    auto result = std::max_element(data.begin(),data.end(),
    [](const TouristVehiclePointer& ptr1, const TouristVehiclePointer& ptr2){
        return ptr1->perHourBookingCharge()<ptr2->perHourBookingCharge();
    });
    return (*result)->perHourBookingCharge();
}

DataContainer ReturnNInstances(const DataContainer &data, unsigned int N)
{
    return DataContainer();
}

bool AreContainerInstanceSamePermitType(const DataContainer &data)
{
    if(data.empty()){
        throw std::runtime_error("data is empty");
    }
    PermitType type = data.front()->permit()->permitType();
    
    bool answer = std::all_of(data.begin(),data.end(),
    [&](const TouristVehiclePointer& t){
        return t->permit()->permitType()==type;
    });
    return answer;
}

std::size_t CountOfInstanceWithTypeCab(const DataContainer &data)
{
    if(data.empty()){
        throw std::runtime_error("data is empty");
    }
    std::count_if(data.begin(),data.end(),
    [](const TouristVehiclePointer& t){
        return t->type()==TouristVehicleType::CAB;
    });
    return 0;
}

std::optional<PermitPointer> FindPermitByID(const DataContainer &data, std::string id)
{
    if(data.empty()){
        throw std::runtime_error("data is empty");
    }

    auto itr = std::find_if(data.begin(),data.end(),
    [&](const TouristVehiclePointer& t){
        return t->number()==id;
    });
    if(itr ==data.end()){
        return std::nullopt;
    }
    else{
        return (*itr)->permit();
        // return itr->get()->permit();
    }
}

int MaxSeatCount(const DataContainer &data,unsigned int N)
{
    if(data.empty()){
        throw std::runtime_error("data is empty");
    }
    
    auto itr = data.begin();
    std::advance(itr,data.size()-N);
    auto result = std::max_element(itr,data.end(),
    [](const TouristVehiclePointer& ptr1, const TouristVehiclePointer& ptr2){
        return ptr1->seatCount()<ptr2->seatCount();
    });
    return (*result)->seatCount();
}

std::list<float> CalculateGstValues(DataContainer &data, std::function<float(const TouristVehiclePointer &ptr)> fn)
{
    if(data.empty()){
        throw std::runtime_error("data is empty");
    }
    std::list<float> result;
    std::transform(data.begin(),data.end(),std::inserter(result,result.begin()),
    fn);
    return result;
}
