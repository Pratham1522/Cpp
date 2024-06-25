#ifndef SALESPERSON_H
#define SALESPERSON_H

#include"Emp.h"

//Salesperson -derive class/child class/sub class
//Employee - base class / Parent class/super class
class Salesperson : public Employee
{
    char *cpt;
    double salesamount,commrate;

    public:

     void calCommission(){  std::cout<<"\n Commission amount="<<salesamount*commrate;  }

        Salesperson();
        Salesperson(int,std::string,double,float,double,double);
        void display();
        ~Salesperson();
        double calTotalsalary();
friend std::ostream&operator<<( std::ostream& os,Salesperson &sp)
{
    os<< static_cast<Employee&>(sp);
    os<<" salesamount ="<<sp.salesamount;
    os<<" commrate ="<<sp.commrate;
    return os;
}
};

#endif // SALESPERSON_H
