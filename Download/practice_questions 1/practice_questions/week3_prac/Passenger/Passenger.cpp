#include "Passenger.h"

Passenger::Passenger(VType id, std::string name, unsigned int age, std::reference_wrapper<Ticket> ticket, float fare)
    :_id{id}, _name{name},_age{age}, _ticket{ticket}, _fare{fare}
{
}
std::ostream &operator<<(std::ostream &os, const Passenger &rhs) {
    os << "_id: ";
    if(std::holds_alternative<int>(rhs._id)){
        os<<std::holds_alternative<int>(rhs._id);
    }
    else if(std::holds_alternative<std::string>(rhs._id)){
        os<<std::holds_alternative<std::string>(rhs._id);
    }
    os << " _name: " << rhs._name
       << " _age: " << rhs._age
       << " _ticket: " << rhs._ticket.get()
       << " _fare: " << rhs._fare;
    return os;
}
