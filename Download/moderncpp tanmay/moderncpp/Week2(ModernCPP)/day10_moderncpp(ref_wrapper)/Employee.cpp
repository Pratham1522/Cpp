#include "Employee.h"


std::ostream &operator<<(std::ostream &os, const Employee &rhs) {
    os << "id: " << rhs.id
       << " name: " << rhs.name
       << " salary: " << rhs.salary
       << " _project: " << rhs._project.get();// without get() it will only give address not value.
    return os;
}

Employee::Employee(int identity, std::string n, int sal, ProjectRef project)
    :id(identity), name(n), salary(sal), _project(project)
{
}
