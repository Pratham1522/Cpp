#pragma once

class Electricity
{
private:
    int sactionLoad;
    int electricitySlab;
    long presentReading;
    long previousReading;
    long consumption;
    double bill;

public:
    Electricity();


    void Accept(); // accept and set values from user.

    // setters
    void setPreviousReading(long pr);
    void setCurrentReading(long cr);
    void setSactionLoad(int sl);
    void setElectricitySlab(int es);
    void setConsumption();

    // getters
    long getPreviousReading();
    long getCurrentReading();
    int getSactionLoad();
    int getElectricitySlab();
    long getConsumption();
    double getBill();

    double calculateElectricityBill(); // Calculate Bill

    void Display(); // Display Details.
};