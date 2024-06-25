#include <iostream>
#include "billnbudget.h"


Electricity::Electricity()
{
    sactionLoad = 0;
    electricitySlab = 0;
    presentReading = 0;
    previousReading = 0;
    setConsumption();
    bill = 0;
}

void Electricity::Accept()
{
    std::cout << "\n**** Enter the Required Details ****";
    std::cout << "\nEnter the sactionLoad : ";
    std::cin >> sactionLoad;
    std::cout << "Enter the electrictySlab : ";
    std::cin >> electricitySlab;
    std::cout << "Enter Present Reading : ";
    std::cin >> presentReading;
    std::cout << "Enter Previous Reading : ";
    std::cin >> previousReading;
    setConsumption();
    std::cout << "\n";
}

// setters.
void Electricity::setPreviousReading(long pr)
{   
    previousReading = pr;
    setConsumption();
}
void Electricity::setCurrentReading(long cr)
{
    presentReading = cr;
    setConsumption();
}
void Electricity::setSactionLoad(int sl)
{
    sactionLoad = sl;
}
void Electricity::setElectricitySlab(int es)
{
    electricitySlab = es;
}
void Electricity::setConsumption(){
    consumption = presentReading - previousReading;
}

// getters
long Electricity::getPreviousReading()
{
    return previousReading;
}
long Electricity::getCurrentReading()
{
    return presentReading;
}
int Electricity::getSactionLoad()
{
    return sactionLoad;
}
int Electricity::getElectricitySlab()
{
    return electricitySlab;
}
long Electricity::getConsumption()
{
    return consumption;
}
double Electricity::getBill()
{
    if (consumption < 1)
    {
        return 0;
    }
    else
    {
        return bill;
    }
}

double Electricity::calculateElectricityBill()
{
    if (consumption < 1)
    {
        bill= 0;
    }
    else
    {
        bill = (sactionLoad * electricitySlab) + (consumption * electricitySlab / 100);
    }
    // bill = (sactionLoad * electricitySlab) + (consumption * electricitySlab / 100);
    return bill;
}
void Electricity::Display()
{
    std::cout << "*** Bill Details are as follow ****";
    std::cout << "\nSaction Load is : " << sactionLoad;
    std::cout << "\nElectricity Slab is : " << electricitySlab;
    std::cout << "\nPrevious Reading is : " << previousReading;
    std::cout << "\nPresent Reading is : " << presentReading;
    std::cout << "\nThis month consumption is :" << consumption << "\n";
}
