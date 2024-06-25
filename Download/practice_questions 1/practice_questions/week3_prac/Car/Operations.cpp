#include "Operations.h"

std::shared_ptr<Operations> Operations:: instance=nullptr;

std::shared_ptr<Operations> Operations::getInstance()
{
    if(!instance){
        instance = std::make_shared<Operations>();
    }
    return instance;
}

void Operations::CreateObject()
{
    data.push_back(
        std::make_shared<Car>("toyota","123",CarCategory::COMMUTE,100,4000.0f)
    );
    data.push_back(
        std::make_shared<Car>("toyota","123",CarCategory::COMMUTE,100,4000.0f)
    );
    data.push_back(
        std::make_shared<Car>("toyota","123",CarCategory::COMMUTE,100,4000.0f)
    );
}

std::optional<Container> Operations::ReturnThoseCarsThatHavePriceMoreThanThreshold(float threshold)
{
    Container result;
    for(std::shared_ptr<Car>& obj:data){
        if(obj->price()>threshold){
            result.push_back(obj);
        }
    }
    return result;
}

Container Operations::ReturnCarWithSameChassisNumber(std::string chassisnum)
{
    
}
