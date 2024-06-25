#ifndef PASSENGER_H
#define PASSENGER_H

#include <iostream>
#include "Ticket.h"
#include<functional>

using RefWrapper = std::reference_wrapper<Ticket>;

class Passenger 
{
private:
    int _id;
    std::string _name;
    int _age;
    RefWrapper _ticket;
    float _fare;
public:
    Passenger() = default; // Default constructor
    Passenger(const Passenger&) = default; // Copy constructor
    Passenger& operator=(const Passenger&) = delete; // Copy assignment operator
    Passenger(Passenger&&) = default; // Move constructor
    Passenger& operator=(Passenger&&) = delete; // Move assignment operator
    ~Passenger() = default; // Destructor

    Passenger(int id,std::string name,int age,RefWrapper ticket, float fare);

    int id() const { return _id; }

    std::string name() const { return _name; }
    void setName(const std::string &name) { _name = name; }

    RefWrapper ticket() const { return _ticket; }
    void setTicket(const RefWrapper &ticket) { _ticket = ticket; }

    int age() const { return _age; }
    void setAge(int age) { _age = age; }

    float fare() const { return _fare; }
    void setFare(float fare) { _fare = fare; }

    friend std::ostream &operator<<(std::ostream &os, const Passenger &rhs);
};

#endif // PASSENGER_H
