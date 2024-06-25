#include <iostream>
#pragma once

class Flight
{
private:
    std::string flightNumber;
    double Distance;
    std::string FlightType;
    double FuelQuantity;
    double Fare;

public:
    // default constructors
    Flight();
    // Parametrised constructor
    Flight(std::string fn, double dist, std::string ft);

    // Take input form user
    void FeedInfo();

    // Display Details
    void ShowInfo();

    // setters
    void setFlightNumber(std::string fn);
    void setDistance(double dist);
    void setFlightType(std::string ft);
    void calculateFare();
    void calculateFuel();

    // getters
    std::string getFightNumber();
    double getDistance();
    std::string getFlightType();
    double getFuelQuantity();
    double getFare();
};
void searchFlight(Flight* obj,int n);
void maxFare(Flight* obj,int n);