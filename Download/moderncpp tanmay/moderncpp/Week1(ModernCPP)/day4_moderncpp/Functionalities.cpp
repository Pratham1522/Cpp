#include "Functionalities.h"

void CreateObjects(Container& data){
    data.push_back(
        new TouristVehicle("Tanmay123",TouristVehicleType::BIKE,6,3.2f,
        new Permit("1234",PermitType::OWNED,7))
    );
    data.push_back(
        new TouristVehicle("Tanmay12345",TouristVehicleType::CAB,4,2.3f,
        new Permit("123456",PermitType::LEASE,3))
    );
}

Container FirstNMatchingInstance(const Container &data, const unsigned int n)
{
    Container MatchInstance;
    if(data.empty()){
        throw std::runtime_error("data is empty");
    }
    if(n<0 || n>data.size()){
        throw std::runtime_error("value of n is greater than data or else less than 0");
    }
    if(n>data.size()){
        throw std::runtime_error("the given number is greater than size of data");
    }
    for(TouristVehicle* ptr:data){
        if(ptr && ptr->seatCount()>=4 && ptr->permit()->permitType()==PermitType::LEASE){
            MatchInstance.push_back(ptr);
            if(MatchInstance.size()==n){
                break;
            }
        }
    }
    if(MatchInstance.empty()){
        throw std::runtime_error("none of the objects satisfy the condition.");
    }
    return MatchInstance;
}

float AverageBookingChargeForGivenType(const Container &data, const TouristVehicleType type)
{
    if(data.empty()){
        throw std::runtime_error("data is empty");
    }
    float total = 0.0f;
    unsigned int count=0;
    for(TouristVehicle* obj:data){
        if(obj && obj->type()==type){
            total+=obj->perHourBookingCharge();
            count++;
        }
    }
    if(count==0){
        throw std::runtime_error("soory no instance of given type exists in data.");
    }
    return total/static_cast<float>(count);
}

std::string FindMaxChargeId(const Container &data)
{
    float maximum=data[0]->perHourBookingCharge();
    std::string maxid=data[0]->permit()->serialNumber();
    if(data.empty()){
        throw std::runtime_error("there is no data. it is empty.");
    }
    for(TouristVehicle* ptr:data){
        if(ptr && ptr->perHourBookingCharge()>maximum){
            maximum = ptr->perHourBookingCharge();
            maxid = ptr->permit()->serialNumber();
        }
    }
    return maxid;
}

Container FindFirstNInstances(const Container &data,const unsigned int n)
{
    Container nInstances;

    return nInstances;
}

/* scenario 1: vector is empty [      ] 
    scenario 2: [0x00h | 0x00h | 0x00h]
*/
void DeleteObjects(Container &data)
{
    if(data.empty()){
        throw std::runtime_error("nothing in the container");
    }
    for(TouristVehicle* ptr:data){
        if(ptr){
            if(ptr->permit()){
                delete ptr->permit();
            }
            delete ptr;
        }
    }
}

/* 
    strategic in releasing resources
        -memory
        -file descriptor(os level file handling)
        -network config pointer

    smart pointers: can help with all these problems.
*/
