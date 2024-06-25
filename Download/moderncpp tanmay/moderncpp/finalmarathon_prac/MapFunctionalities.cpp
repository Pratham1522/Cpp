#include "MapFunctionalities.h"
#include<numeric>

void CreateObjects(DataContainer& data){
    data.emplace(
        MapEntry("1",std::make_shared<TouristVehicle>("1",TouristVehicleType::CAB,4,1000.0f,
        std::make_shared<Permit>("s1",PermitType::LEASE,3)))
    );
    data.emplace(
        MapEntry("2",std::make_shared<TouristVehicle>("2",TouristVehicleType::CAB,4,2000.0f,
        std::make_shared<Permit>("s1",PermitType::LEASE,3)))
    );
}

/* 
first N instances satisfying conditions
-seat count >=4 & permittype :: lease
 */
std::optional<std::list<TouristVehiclePtr>> FindMatchingInstaces(const DataContainer& data,unsigned int N){
    if(data.empty()){
        throw std::runtime_error("data is empty");
    }
    std::list<TouristVehiclePtr> result;
    std::for_each(data.begin(),data.end(),
    [&](const MapEntry& mp){
        if(mp.second->seatCount()>=4 && mp.second->permit()->permitType()==PermitType::LEASE){
            result.push_back(mp.second);
        }
    });
    result.resize(N);
    return result;
}

/* average per hour booking charge */
float AveragePerBookingCharges(const DataContainer& data){
    float average = std::accumulate(data.begin(),data.end(),0.0f,
    [](float avg,const MapEntry& mp){
        return avg+mp.second->perHourBookingCharge();
    });
    return average/data.size();
}

/* max per hour booking charges */
float MaxPerBookingCharges(const DataContainer& data){
    float maximum = (*data.begin()).second->perHourBookingCharge();
    auto itr = std::max_element(data.begin(),data.end(),
    [](const MapEntry& m1,const MapEntry& m2){
        return m1.second->perHourBookingCharge() < m2.second->perHourBookingCharge();
    });
    return (*itr).second->perHourBookingCharge();
}

/* returns first N instances in a container */
std::list<TouristVehiclePtr> ReturnNInstances(const DataContainer& data, unsigned int N){
    if(data.empty()){
        throw std::runtime_error("data not found");
    }
    std::list<TouristVehiclePtr> result;
    /* 
    for each pair in the input data,
    a) extract pair.second
    b) push_back pair.second into the result */

    auto fn = [](const MapEntry& p){
        return p.second;
    };
    std::for_each_n(data.begin(),N,
    [&](const MapEntry& p){
        result.push_back(p.second);
    });
    return result;
}

/* check if all instances have the same permitType */
bool AreContainerInstanceSamePermitType(const DataContainer& data){
    if(data.empty()){
        throw std::runtime_error("data is empty");
    }
    PermitType ptype = (*data.begin()).second->permit()->permitType();
    bool flag = std::all_of(data.begin(),data.end(),
    [&](const MapEntry& mp){
        return mp.second->permit()->permitType()==ptype;
    });
    return flag;
}

/* return count of instances whose vehicle tpe is CAB */
std::size_t CountOfInstanceWithTypeCab(const DataContainer& data){
    if(data.empty()){
        throw std::runtime_error("data is empty");
    }
    auto  itr = std::count_if(data.begin(),data.end(),
    [](const MapEntry& p){
        return p.second->type()==TouristVehicleType::CAB;
    });
    return itr;
}

//when using map use const lvalue reference of pair or use rvalue of pair
/* return permit ptr absed on id value */
std::optional<PermitPointer> FindPermitByID(const DataContainer& data,std::string id){
    if(data.empty()){
        throw std::runtime_error("data is empty");
    }
    auto itr = std::find_if(data.begin(),data.end(),
    [&](const MapEntry& p){// or (MapEntry&& p)
        return p.second->number()==id;
    });
    if(itr==data.end()){
        return std::nullopt;
    }
    else{
        return (*itr).second->permit();
    }
}

/* return maximum seat count from last N instances  */
int MaxSeatCount(const DataContainer& data,unsigned int N){
    auto itr = std::max_element(data.begin(),data.end(),
    [](const MapEntry& m1,const MapEntry& m2){
        return m1.second->seatCount() < m2.second->seatCount();
    });
    return (*itr).second->seatCount();
}

/* calculate gst on per hour booking charge based on a unary operator
passed by the user for all instances and  */
std::list<float> CalculateGstValues(DataContainer& data, 
std::function<float(const TouristVehiclePtr& ptr)> fn){
//     std::list<float> result;
//     std::copy_if(data.begin(),data.end(),
//     std::inserter(result,result.begin()),
//     [](const MapEntry& mp){
//         return mp.second->perHourBookingCharge();
//     });
//     return result;
}


