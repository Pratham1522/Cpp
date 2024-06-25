#ifndef PASSENGER_H
#define PASSENGER_H

#include <iostream>
#include<functional>
#include<variant>
#include "Ticket.h"

using VType = std::variant<int,std::string>;
class Passenger 
{
private:
    VType _id;
    std::string _name;
    unsigned int _age;
    std::reference_wrapper<Ticket> _ticket;
    float _fare;
public:
    Passenger() = default; // Default constructor
    Passenger(const Passenger&) = default; // Copy constructor
    Passenger& operator=(const Passenger&) = delete; // Copy assignment operator
    Passenger(Passenger&&) = default; // Move constructor
    Passenger& operator=(Passenger&&) = delete; // Move assignment operator
    ~Passenger() = default; // Destructor

    Passenger(VType id,std::string name,unsigned int age,std::reference_wrapper<Ticket> ticket,float fare);

    VType id() const { return _id; }

    std::string name() const { return _name; }
    void setName(const std::string &name) { _name = name; }

    unsigned int age() const { return _age; }

    std::reference_wrapper<Ticket> ticket() const { return _ticket; }
    void setTicket(const std::reference_wrapper<Ticket> &ticket) { _ticket = ticket; }

    float fare() const { return _fare; }
    void setFare(float fare) { _fare = fare; }

    friend std::ostream &operator<<(std::ostream &os, const Passenger &rhs);
};

#endif // PASSENGER_H
