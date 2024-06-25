#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>

class Employee 
{
private:
    std::string _name;
    float _salary;
public:
    Employee() = default; // Default constructor
    Employee(const Employee&) = delete; // Copy constructor
    Employee& operator=(const Employee&) = delete; // Copy assignment operator
    Employee(Employee&&) = delete; // Move constructor
    Employee& operator=(Employee&&) = delete; // Move assignment operator
    ~Employee() = default; // Destructor

    Employee(std::string name, float salary) : _name(name), _salary(salary){}

    void payTax(){
        if(_salary<50000.0f){
            std::cout<<"no tax for you!!\n";
        }
        else if(_salary>=50000.0f && _salary<=100000.0f){
            std::cout<<"20% tax for you!!\n";
        }
    }

    std::string name() const { return _name; }
    void setName(const std::string &name) { _name = name; }

    float salary() const { return _salary; }
    void setSalary(float salary) { _salary = salary; }

};

#endif // EMPLOYEE_H

