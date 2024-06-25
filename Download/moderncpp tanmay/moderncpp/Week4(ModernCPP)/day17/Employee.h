#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <string>
#include <ostream>

class Employee
{
    private:
    std::string _id{""};
    std::string _name{""};
    float _salary{0.0f};
    int _age{0};
    std::string _location{""};

    public:
    Employee() = default;
    ~Employee() = default;

    Employee(const Employee&) = default;
    Employee& operator=(const Employee&) = default;

    Employee(Employee&) = default;
    Employee& operator=(Employee&) = default;

    Employee(    std::string _id, std::string _name, float _salary, int _age, std::string _location); 

    std::string id() const { return _id; }

    std::string name() const { return _name; }

    float salary() const { return _salary; }

    int age() const { return _age; }

    std::string location() const { return _location; }

    friend std::ostream &operator<<(std::ostream &os, const Employee &rhs);

    float operator+(const Employee& rhs) { return _salary + rhs.salary(); }
};

#endif // EMPLOYEE_H
