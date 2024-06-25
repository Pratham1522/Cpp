#pragma once
#include<iostream>
#include"Vehicle.h"

class ParkingBill{
    private:
        int billnumber;
        static int count;
        Vehicle ParkedVehicle;
        float parkingChargesAmount;
        static const int ParkingCharges2Wheeler[4];
        static const int parkingCharges4Wheeler[4];

    public:
        ParkingBill();
        ParkingBill(Vehicle &);  
        void operator=(Vehicle &);
        float ParkingChargeAmountcal();
        friend std::ostream& operator<<(std::ostream&,ParkingBill &);


        int getBillnumber() const { return billnumber; }
        void setBillnumber(int billnumber_) { billnumber = billnumber_; }

        static int getCount() { return ParkingBill::count; }
        static void setCount(int count) { ParkingBill::count = count; }

        float getParkingChargesAmount() const { return parkingChargesAmount; }
        void setParkingChargesAmount(float parkingChargesAmount_) { parkingChargesAmount = parkingChargesAmount_; }

};
