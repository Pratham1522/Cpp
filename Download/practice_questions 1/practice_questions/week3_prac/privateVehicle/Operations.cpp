#include "Operations.h"

Operations *Operations::instance=nullptr;

Operations *Operations::getInstance()
{
    if(!instance){
        instance = new Operations();
    }
    else{
        return instance;
    }
    return instance;
}

void Operations::CreateObjects()
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

void Operations::Print()
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

void Operations::ReturnAverage()
{
    float sum=0.0f;
    for(auto& obj:data){
        if(std::holds_alternative<std::shared_ptr<PrivateVehicle>>(obj)){
            sum += std::get<1>(obj)->vehiclePrice();
        }
        else if(std::holds_alternative<std::shared_ptr<TouristVehicle>>(obj)){
            sum += std::get<0>(obj)->vehiclePrice();
        }
    }
    std::cout<< static_cast<float>(sum/data.size());
}

float Operations::ReturnTrueIfAllPriceAbove5L()
{
    float current_vehicle_price = 0.0f;
    for(VType& obj:data){
        std::visit([&](auto&& val){current_vehicle_price = val->vehiclePrice();},obj);
        if(current_vehicle_price<=500000.0f){
            return false;
        }
    }
    return true;
}

std::optional<PrivateContainer> Operations::FetchPrivateVehiclePointer()
{


    return std::optional<PrivateContainer>();
}
