#include "Passenger.h"

Passenger::Passenger(int id, std::string name, int age, RefWrapper ticket, float fare)
    :_id{id},_name{name}, _age{age}, _ticket{ticket}, _fare{fare}
{
}
std::ostream &operator<<(std::ostream &os, const Passenger &rhs) {
    os << "_id: " << rhs._id
       << " _name: " << rhs._name
       << " _age: " << rhs._age
       << " _ticket: " << rhs._ticket.get()
       << " _fare: " << rhs._fare;
    return os;
}
