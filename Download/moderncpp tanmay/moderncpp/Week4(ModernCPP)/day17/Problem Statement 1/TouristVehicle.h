#ifndef TOURISTVEHICLE_H
#define TOURISTVEHICLE_H

#include <iostream>
#include <memory>
#include "TouristVehicleType.h"
#include "Permit.h"

class TouristVehicle
{
    private:
    std::string _number;
    TouristVehicleType _type;
    int _seat_count;
    float _per_hour_booking_charge;
    std::shared_ptr<Permit> _permit;

    public:
    TouristVehicle() = delete;
    ~TouristVehicle() = default;

    TouristVehicle(const TouristVehicle&) = delete;
    TouristVehicle& operator=(const TouristVehicle&) = delete;

    TouristVehicle(TouristVehicle&&) = default;
    TouristVehicle& operator=(TouristVehicle&&) = default;

    TouristVehicle(std::string number, TouristVehicleType type, int count, float charges, std::shared_ptr<Permit> _permit);

    std::string number() const { return _number; }
    
    TouristVehicleType type() const { return _type; }
    
    int seatCount() const { return _seat_count; }
    
    float perHourBookingCharge() const { return _per_hour_booking_charge; }
    void setPerHourBookingCharge(float per_hour_booking_charge) { _per_hour_booking_charge = per_hour_booking_charge; }

    std::shared_ptr<Permit> permit() const { return _permit; }

    friend std::ostream &operator<<(std::ostream &os, const TouristVehicle &rhs);

    

};

#endif // TOURISTVEHICLE_H


/*
    Two ways I can write TouristVehicle: (if default constructor is enabled)
        TouristVehicle t1; // --> garbage values
        TouristVehicle t2{} // --> "", BIKE, 0, 0.0f, nullptr
*/