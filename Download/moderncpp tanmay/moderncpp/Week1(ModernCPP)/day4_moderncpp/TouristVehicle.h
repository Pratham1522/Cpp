#ifndef TOURISTVEHICLE_H
#define TOURISTVEHICLE_H
#include<iostream>
#include "TouristVehicleType.h"
#include "Permit.h"

class TouristVehicle
{
private:
    std::string _number;
    TouristVehicleType _type {TouristVehicleType::BIKE};
    int _seat_count;
    float _per_hour_booking_charge;
    Permit* _permit;
public:
    TouristVehicle() = delete;
    ~TouristVehicle();
    TouristVehicle(const TouristVehicle&) = delete;
    TouristVehicle& operator=(const TouristVehicle&) = delete;
    TouristVehicle& operator=(TouristVehicle&&) = delete;
    TouristVehicle(const TouristVehicle&&) = delete;

    TouristVehicle(std::string number, TouristVehicleType type,int count,float charges,Permit* p);

    std::string number() const { return _number; }

    TouristVehicleType type() const { return _type; }
    void setType(const TouristVehicleType &type) { _type = type; }

    int seatCount() const { return _seat_count; }

    float perHourBookingCharge() const { return _per_hour_booking_charge; }

    Permit* permit() const { return _permit; }
    void setPermit(Permit* permit) { _permit = permit; }

    friend std::ostream &operator<<(std::ostream &os, const TouristVehicle &rhs);
};

#endif // TOURISTVEHICLE_H
