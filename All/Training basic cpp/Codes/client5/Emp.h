#ifndef EMP_H
#define EMP_H

#include <iostream>
// A class with virtual function is called as Polymorphic class
// class without virtual function is called as Concrete class- we can create object of that class
class Employee
{
private:
    int empid;
    std::string ename;
    double esalary;
    double HRA, FA, PTAX, PF;
    float experience;
    void calculateAllowances()
    {
        HRA = esalary * 0.02;
        FA = esalary * 0.03;
        PTAX = esalary * 0.05;
        PF = esalary * 0.02;
    }

public:
    Employee();
    Employee(int eid, std::string enm, double esal, float exp);
   virtual  ~Employee();
   virtual double calTotalsalary();
   virtual void display();
    friend std::ostream &operator<<(std::ostream &os, const Employee &e);
};

#endif // EMP_H
