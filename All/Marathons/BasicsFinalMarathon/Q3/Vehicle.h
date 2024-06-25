#pragma once
#include<iostream>
#include<cstring>

enum vtype {
    TWOWH ,FOURWH
};
class Vehicle{
    private:
        char* vehicle_num=new char[10];
        vtype vehicle_type ;
        int parking_hrs;
        static int parkingID;
        static int vehiclescount;
        int totalvehicles;

    public:
        Vehicle();
        Vehicle(Vehicle&);
        ~Vehicle();

        void operator=(Vehicle&);
        friend std::ostream& operator<< (std::ostream& ,Vehicle&);
        friend std::istream& operator>> (std::istream& ,Vehicle&);
        static void showNumberOf_vehicles();

        char* vehicleNum() const { return vehicle_num; }
        void setVehicleNum(char* vehicleNum) { vehicle_num = vehicleNum; }

        vtype vehicleType() const { return vehicle_type; }
        void setVehicleType(const vtype &vehicleType) { vehicle_type = vehicleType; }

        int parkingHrs() const { return parking_hrs; }
        void setParkingHrs(int parkingHrs) { parking_hrs = parkingHrs; }

        int getParkingID() const { return parkingID; }
        void setParkingID(int parkingID_) { parkingID = parkingID_; }    
};
