#include "Vehicle.h"

Vehicle::Vehicle()
{
    strcpy(vehicle_num,"MH15FZ0001");
    vehicle_type=TWOWH;
    parking_hrs=0;
    parkingID++;
    vehiclescount++;
    totalvehicles=vehiclescount;
}

Vehicle::Vehicle(Vehicle &obj)
{
    strcpy(vehicle_num,obj.vehicle_num);
    vehicle_type=obj.vehicle_type;
    parking_hrs=obj.parking_hrs;
    parkingID++;
    vehiclescount++;
    totalvehicles=vehiclescount;
}

Vehicle::~Vehicle()
{
    delete []vehicle_num;
    totalvehicles--;
}

void Vehicle::operator=(Vehicle &obj)
{
    strcpy(vehicle_num,obj.vehicle_num);
    vehicle_type=obj.vehicle_type;
    parking_hrs=obj.parking_hrs;
    parkingID++;
    vehiclescount++;
    totalvehicles=vehiclescount;
}

void Vehicle::showNumberOf_vehicles()
{ 
    std::cout<<"Total Vehicles : "<<Vehicle::vehiclescount;

}

std::ostream &operator<<(std::ostream &o, Vehicle &obj)
{
    o<<"Vehicle Number : "<<obj.vehicle_num;
    o<<"\nVehicle Type : ";
    switch(obj.vehicle_type){
        case 0 : o<<"TWOWH";
        break;
        case 1 : o<<"FOURWH";
        break;
    }
    o<<"\nParking hours : "<<obj.parking_hrs;
    o<<"\nTotal Vehicles : "<<Vehicle::vehiclescount;
    return o;
}

std::istream& operator>>(std::istream& is, Vehicle &obj)
{
    std::cout<<"\nEnter Vehicles Details \n";
    std::cout<<"\nEnter Vehicle Number : ";
    is >> obj.vehicle_num;
    std::cout<<"Press 0 for TWOWH \nPress 1 for FOURWH \nEnter Vehicle Type : ";
    int temp;
    is >> temp;
    switch (temp){
        case 0 : obj.vehicle_type=TWOWH;
        break;
        case 1 : obj.vehicle_type=FOURWH;
    }
    std::cout<<"Enter Parking hours : ";
    is >> obj.parking_hrs;
    return is;
}
