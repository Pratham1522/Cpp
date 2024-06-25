#ifndef EMPLOYEE_H
#define EMPLOYEE_H


#include <iostream>

class Employee 
{
private:
    std::string str{""};
public:
    Employee() = default; // Default constructor
    Employee(const Employee&) = default; // Copy constructor
    Employee& operator=(const Employee&) = delete; // Copy assignment operator
    Employee(Employee&&) = delete; // Move constructor
    Employee& operator=(Employee&&) = delete; // Move assignment operator
    ~Employee() = default; // Destructor
    Employee(std::string s):str{s}{};

    void Display()
    {
        std::cout<<str<<" ";
    }

};

#endif // EMPLOYEE_H
