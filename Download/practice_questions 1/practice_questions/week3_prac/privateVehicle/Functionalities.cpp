#include "Functionalities.h"



void CreateObjects(Container &data, PermitContainer& permits)
{
    permits.push_back(Permit("100",2020));
    permits.push_back(Permit("101",2015));
    permits.push_back(Permit("102",2005));
    PermitContainer::iterator itr = permits.begin();
    if(itr!=permits.end()){
        data.push_back(std::make_shared<TouristVehicle>("0",340000.0f,VehicleType::BUS,*itr++));
    }
    if(itr!=permits.end()){
        data.push_back(std::make_shared<TouristVehicle>("1",340100.0f,VehicleType::CAB,*itr++));
    }
    if(itr!=permits.end()){
        data.push_back(std::make_shared<TouristVehicle>("2",12400.0f,VehicleType::OTHER,*itr++));
    }
    data.push_back(std::make_shared<PrivateVehicle>("3",94000.0f,EngineType::DIESEL));
    data.push_back(std::make_shared<PrivateVehicle>("4",134000.0f,EngineType::PETROL));
}

void Print(Container &data)
{
    for(auto& obj:data){
        if(std::holds_alternative<std::shared_ptr<PrivateVehicle>>(obj)){
            std::cout<<*std::get<1>(obj)<<"\n";
        }
        else if(std::holds_alternative<std::shared_ptr<TouristVehicle>>(obj)){
            std::cout<<*std::get<0>(obj)<<"\n";
        }
    }
}
