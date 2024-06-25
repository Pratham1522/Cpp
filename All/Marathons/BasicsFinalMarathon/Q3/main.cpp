#include"Vehicle.h"
#include"ParkingBill.h"
#include<iostream>
#include<cstring>

int Vehicle::vehiclescount=0;
int Vehicle::parkingID=0;
int ParkingBill::count=0;
const int ParkingBill::ParkingCharges2Wheeler[4]={10,20,30,100};
const int ParkingBill::parkingCharges4Wheeler[4]={20,30,40,200};

int main(){
    // Vehicle* v=new Vehicle[3];
    // for(int i=0;i<3;i++){
    //     std::cin>>v[i];
    //     std::cout<<v[i];
    // }
    // ParkingBill p1(v[0]);
    // ParkingBill p2(v[1]);
    // ParkingBill p3(v[2]);

    Vehicle v1,v2,v3;
    std::cin>>v1>>v2>>v3;
    ParkingBill p[3]={v1,v2,v3};
    

    // std::cout<<p1;
    // std::cout<<p2;
    // std::cout<<p3;

    // std::cout<<p1.getParkingChargesAmountcal()+p2.getParkingChargesAmountcal()+p3.getParkingChargesAmountcal();

    // std::cout<<"Parking Charges of 2 Wheelers : ";
    // for(int i=0;i<4;i++){
    //     std::cout<<ParkingBill::ParkingCharges2Wheeler[i] <<" ";
    // }
    // std::cout<<"Parking Charges of 2 Wheelers : ";
    // for(int i=0;i<4;i++){
    //     std::cout<<ParkingBill::ParkingCharges4Wheeler[i] <<" ";
    // }


}
