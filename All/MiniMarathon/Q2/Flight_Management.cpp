#include <iostream>
#include "Flight_Management.h"

Flight::Flight()
{
    flightNumber = "***";
    Distance = 0;
    FlightType = "***";
    FuelQuantity = 0;
    Fare = 0;
}
// Parametrised constructor
Flight::Flight(std::string fn, double dist, std::string ft)
{
    flightNumber = fn;
    Distance = dist;
    FlightType = ft;
    calculateFuel();
    calculateFare();
}
void Flight::FeedInfo()
{
    std::cout << "\n**** Enter the Required Details ****";
    std::cout << "\nEnter Flight Number : ";
    std::cin >> flightNumber;
    std::cout << "Enter Flight Distance : ";
    std::cin >> Distance;
    std::cout << "Enter Flight Type : ";
    std::cin >> FlightType;
    calculateFuel();
    calculateFare();
    std::cout << "\n";
}

void Flight::ShowInfo()
{
    std::cout << "*** Flight Details are as follow ****";
    std::cout << "\nFlight Number :" << flightNumber;
    std::cout << "\nFlight Distance : " << Distance;
    std::cout << "\nFlight Type : " << FlightType;
    std::cout << "\nRequired Fuel : " << FuelQuantity;
    std::cout << "\nRequired Fare : " << Fare;
    std::cout << "\n";
}

// setters
void Flight::setFlightNumber(std::string fn)
{
    flightNumber = fn;
}
void Flight::setDistance(double dist)
{
    Distance = dist;
}
void Flight::setFlightType(std::string ft)
{
    FlightType = ft;
}
void Flight::calculateFare()
{
    if (Distance <= 1000)
    {
        Fare = 5000;
    }
    else if (Distance <= 1500)
    {
        Fare = 11000;
    }
    else if (Distance <= 2000)
    {
        Fare = 22000;
    }
    else
    {
        Fare = 30000;
    }
}
void Flight::calculateFuel()
{
    if (Distance <= 1000)
    {
        FuelQuantity = 4000;
    }
    else if (Distance <= 1500)
    {
        FuelQuantity = 6000;
    }
    else if (Distance <= 2000)
    {
        FuelQuantity = 7500;
    }
    else
    {
        FuelQuantity = 10000;
    }
}

// getters
std::string Flight::getFightNumber()
{
    return flightNumber;
}
double Flight::getDistance()
{
    return Distance;
}
std::string Flight::getFlightType()
{
    return FlightType;
}
double Flight::getFuelQuantity()
{
    return FuelQuantity;
}
double Flight::getFare()
{
    return Fare;
}
void searchFlight(Flight* obj,int n){
    std::string key;
    std::cout << "\n *************************************";
    std::cout << "\n Enter the Flight Number to Search : ";
    std::cin >> key;
    int flag = 0;
    for (int i = 0; i < n; i++)
    {
        if (obj[i].getFightNumber() == key)
        {
            std::cout << "\n Flight " << i + 1 << " Found. \n";
            flag = 1;
            break;
        }
    }
    if (flag == 0)
    {
        std::cout << "\n No Flight Found \n";
    }
}
void maxFare(Flight* obj,int n){
    std::cout << "\n *************************************";
    double mfare = 0;
    int val = 0;
    for (int i = 0; i < n; i++)
    {
        if (obj[i].getFare() > mfare)
        {
            mfare = obj[i].getFare();
            val = i ;
        }
    }
    std::cout << "\n Flight with MAX Fare : \n";
    std::cout << "\nFlight Number : " << obj[val].getFightNumber() << "\nFlight Fare : " << obj[val].getFare() << "\n";
}