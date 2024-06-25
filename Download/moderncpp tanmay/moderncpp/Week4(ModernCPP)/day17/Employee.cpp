#include "Employee.h"
std::ostream &operator<<(std::ostream &os, const Employee &rhs) {
    os << "_id: " << rhs._id
       << " _name: " << rhs._name
       << " _salary: " << rhs._salary
       << " age: " << rhs._age
       << " _location: " << rhs._location;
    return os;
}

Employee::Employee(std::string _id, std::string _name, float _salary, int _age, std::string _location)
        : _id{_id}, _name{_name}, _salary{_salary}, _age{_age}, _location{_location}
{
}