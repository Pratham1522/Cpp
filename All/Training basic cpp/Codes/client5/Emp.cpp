#include <iostream>
#include"Emp.h"

Employee::Employee() : empid(1), ename("Jay"), esalary(15000), experience(1.5f)
{
    calculateAllowances();
    std::cout << "\n Employee() called ";
}
Employee::Employee(int eid, std::string enm, double esal, float exp) : empid(eid), ename(enm), esalary(esal), experience(exp)
{
    calculateAllowances();
    std::cout << "\n Employee(...) called ";
}

double Employee::calTotalsalary()
{
    std::cout<<"\n Employee calTotalsalary() fun \n";
    return esalary - FA - HRA - PTAX - PF;
}
void Employee::display()
{
    std::cout << "\n Id=" << empid << " Name=" << ename << " salary=" << esalary << " experience=" << experience;
}
Employee::~Employee()
{
    std::cout << "\n ~Employee() called ";
}
std::ostream &operator<<(std::ostream &os, const Employee &e)
{
    os << "\n Id=" << e.empid << " Name=" << e.ename << " salary=" << e.esalary << " experience=" << e.experience;
    return os;
}