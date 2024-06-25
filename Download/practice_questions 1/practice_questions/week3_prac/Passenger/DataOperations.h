#ifndef DATAOPERATIONS_H
#define DATAOPERATIONS_H

#include <iostream>
#include "Passenger.h"
#include<memory>
#include<future>
#include<thread>
#include<mutex>
#include<condition_variable>
#include<vector>

// using OpsPtr = std::shared_ptr<DataOperations>;
using Container = std::vector<std::shared_ptr<Passenger>>;
using TicketContainer = std::vector<Ticket>;

class DataOperations 
{
private:
    static std::shared_ptr<DataOperations> ptr;
    TicketContainer tickets;
    Container m_data;
    std::mutex mt;
    std::condition_variable cv;
    bool flag = false;
    int n;
public:
    DataOperations() = default; // Default constructor
    DataOperations(const DataOperations&) = delete; // Copy constructor
    DataOperations& operator=(const DataOperations&) = delete; // Copy assignment operator
    DataOperations(DataOperations&&) = delete; // Move constructor
    DataOperations& operator=(DataOperations&&) = delete; // Move assignment operator
    ~DataOperations() = default; // Destructor
    static std::shared_ptr<DataOperations> getInstance();
    void CreateObjects();
    void DisplayPassengerInstanceOfSameID(VType id);
    Container NameDoesNotMatchContainer(std::future<std::string>& name);
    void Print();

    void Input();
    void FacOfInput();
};

#endif // DATAOPERATIONS_H
