#include "Functionalities.h"
#include<vector>

void createObject(Container &data)
{
    data.push_front(
        new TouristVehicle("123",Vehicle::BUS,8,4.0f,
        new Permit("12345",Own::LEASE,5)
        )
    );
    data.push_front(
        new TouristVehicle("111",Vehicle::BIKE,5,3.0f,
        new Permit("11111",Own::LEASE,3)
        )
    );
    data.push_front(
        new TouristVehicle("222",Vehicle::CAB,4,2.3f,
        new Permit("22222",Own::OWN,4)
        )
    );
}
std::vector<TouristVehicle*> find(Container &data)
{
    std::vector<TouristVehicle*>v1;
    for(Container::iterator obj=data.begin();obj!=data.end();++obj){
        if((*obj)->seatCount()>=4 && (*obj)->permit()->permitType()==Own::LEASE){
            //std::cout<<(*obj)->number()<<std::endl;
            v1.push_back(*obj);
        }
    }
    return v1;
}

void findaverage(Container &data)
{
    double avg=0.0f;
    int count=0;
    for(Container::iterator obj=data.begin();obj!=data.end();++obj){
        avg+= (*obj)->perHourBookingCharge();
        count++;
    }
    std::cout<<avg/count<<std::endl;
}

void findmaximum(Container &data)
{
    int maximum=0;
    std::string serialnum;
    for(Container::iterator obj=data.begin();obj!=data.end();++obj){
        if(maximum<(*obj)->perHourBookingCharge()){
            maximum = (*obj)->perHourBookingCharge();
            serialnum = (*obj)->permit()->serialNumber();
        }
    }
    std::cout<<"Maximum is: "<<maximum<<" and its serial number is: "<<serialnum<<std::endl;
}

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