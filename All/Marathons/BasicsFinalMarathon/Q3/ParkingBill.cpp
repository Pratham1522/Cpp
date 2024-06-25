#include "ParkingBill.h"

ParkingBill::ParkingBill(Vehicle &obj)
{   
    count++;
    ParkedVehicle=obj;
    billnumber=count;
}

void ParkingBill::operator=(Vehicle &obj)
{
    count++;
    ParkedVehicle=obj;
    billnumber=count;
}

ParkingBill::ParkingBill()
{
    parkingChargesAmount=0;
}

float ParkingBill::ParkingChargeAmountcal()
{
    if(ParkedVehicle.vehicleType()==TWOWH){
        int hrs=ParkedVehicle.parkingHrs();
        if(hrs<=3){
            parkingChargesAmount=hrs*10;
        }else if(hrs<=6){
            parkingChargesAmount=hrs*20;
        }else if(hrs<=12){
            parkingChargesAmount=hrs*30;
        }else{
            parkingChargesAmount=hrs*100;
        }
    }else if(ParkedVehicle.vehicleType()==FOURWH){
        int hrs=ParkedVehicle.parkingHrs();
        if(hrs<=3){
            parkingChargesAmount=hrs*20;
        }else if(hrs<=6){
            parkingChargesAmount=hrs*30;
        }else if(hrs<=12){
            parkingChargesAmount=hrs*40;
        }else{
            parkingChargesAmount=hrs*200;
        }
    }
    return parkingChargesAmount;
}

std::ostream& operator<<(std::ostream &o, ParkingBill &obj)
{
    o<<"Bill number : "<<obj.billnumber;
    std::cout<<obj.ParkedVehicle;
    o<<"\nParking Charges :"<<obj.parkingChargesAmount;
    return o;
}
