#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include <iostream>
#include<functional>
#include "Project.h"

using ProjectRef = std::reference_wrapper<Project>;

class Employee 
{
private:
    int id{0};
    std::string name{""};
    int salary{0};
    ProjectRef _project;

public:
    Employee() = delete; // Default constructor
    Employee(const Employee&) = delete; // Copy constructor
    Employee& operator=(const Employee&) = delete; // Copy assignment operator
    Employee(Employee&&) = delete; // Move constructor
    Employee& operator=(Employee&&) = delete; // Move assignment operator
    ~Employee() = default; // Destructor

    Employee(int identity, std::string n, int sal, ProjectRef project);

    int getId() const { return id; }

    std::string getName() const { return name; }
    void setName(const std::string &name_) { name = name_; }

    int getSalary() const { return salary; }

    ProjectRef project() const { return _project; }
    void setProject(const ProjectRef &project) { _project = project; }


    friend std::ostream &operator<<(std::ostream &os, const Employee &rhs);
};

#endif // EMPLOYEE_H
