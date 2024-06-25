#include "Functionalities.h"

void CreateOjects(Container &data)
{
    data.push_back(
        new Device("123","tanmay",100, 20, Devicetype::MOBILE,
        new License(123,LicenseType::RENTED),
        new Owner("tanmay"))
    );
    data.push_back(
        new Device("222","abcd",100, 20, Devicetype::WORKSTATION,
        new License(222,LicenseType::OWNED),
        new Owner("abcd"))
    );
    data.push_back(
        new Device("111","harry",50, 1.7, Devicetype::ACCESSORY,
        new License(111,LicenseType::RENTED),
        new Owner("harry"))
    );
}

void DeleteObjects(Container &data)
{
    for(Device* obj:data){
        if(obj){
            if(obj->license()){
                delete obj->license();
                if(obj->owner()){
                delete obj->owner();
                }
            }
        }
        delete obj;
    }
}

unsigned int CheckCondition(Container &data)
{
    unsigned int count=0;
    for(Device* obj:data){
        if((obj->sarValue()>=1.0 && obj->sarValue()<=1.5 && obj->license()->type()==LicenseType::OWNED) || (obj->sarValue()>=1.5 && obj->sarValue()<=2.0 && obj->license()->type()==LicenseType::RENTED)){
            count++;
        }
    }
    return count;
}

float CalculateDiscountPrice(Container &data, Devicetype type)
{
    float discount=0.0f;
    float answer;
    for(Device* obj:data){
        if(obj->type()==Devicetype::ACCESSORY){
            discount = obj->price() * 0.1;
            answer = obj->price()-discount;
            break;
        }
        else if(obj->type()==Devicetype::MOBILE){
            discount = obj->price() * 0.25;
            answer = obj->price()-discount;
            break;
        }
        else if(obj->type()==Devicetype::WORKSTATION){
            discount = obj->price() * 0.2;
            answer = obj->price()-discount;
            break;
        }
    }
    return answer;
}
