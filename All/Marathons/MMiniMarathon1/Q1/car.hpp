#pragma once
#include "vendor.hpp"


class Car
{
private:
    string _number;//reg number
    int _seat_count;
    float _per_km_charge;
    Vendor* _vendor;

public:
    
    Car(string num,int seats=4,float charge=15,Vendor* v=nullptr):_number(num),_seat_count(seats),_per_km_charge(charge),_vendor(v){} //constructor

    string getNumber() const { return _number; }

    int getSeatCount() const { return _seat_count; }

    float getPerKmCharge() const { return _per_km_charge; }
    void setPerKmCharge(float per_km_charge) { _per_km_charge = per_km_charge; }

    Vendor* getVendor() const { return _vendor; }
    void setVendor(Vendor* vendor) { _vendor = vendor; }

    ~Car()
    {
        delete _vendor;
        _vendor =nullptr;
    }

};    