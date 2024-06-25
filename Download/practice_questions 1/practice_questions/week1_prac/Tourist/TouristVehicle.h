#ifndef TOURISTVEHICLE_H
#define TOURISTVEHICLE_H
#include<iostream>
#include "Permit.h"
#include "Own.h"
#include "Vehicle.h"

class TouristVehicle
{
private:
    std::string _number{""};
    Vehicle _type{0};
    unsigned int _seatCount{1};
    float _perHourBookingCharge{0.0f};
    Permit *_permit {nullptr};
public:
    TouristVehicle() = default;
    ~TouristVehicle();
    TouristVehicle(const TouristVehicle&) = delete;
    TouristVehicle& operator=(const TouristVehicle&) = delete;
    TouristVehicle(std::string number,Vehicle vehicle_type, unsigned int count, float charges, Permit* permit);

    std::string number() const { return _number; }
    void setNumber(const std::string &number) { _number = number; }

    Vehicle type() const { return _type; }

    unsigned int seatCount() const { return _seatCount; }
    void setSeatCount(unsigned int seatCount) { _seatCount = seatCount; }

    float perHourBookingCharge() const { return _perHourBookingCharge; }
    void setPerHourBookingCharge(float perHourBookingCharge) { _perHourBookingCharge = perHourBookingCharge; }

    Permit *permit() const { return _permit; }
    void setPermit(Permit *permit) { _permit = permit; }

    friend std::ostream &operator<<(std::ostream &os, const TouristVehicle &rhs);
    
};

#endif // TOURISTVEHICLE_H
