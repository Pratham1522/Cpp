
#ifndef MANAGER_H
#define MANAGER_H

#include"Emp.h"

class Manager:public Employee
{
    int numberof_subordinates;
    double incentiveper_subordinate;
 
 public:
        Manager():numberof_subordinates(1),incentiveper_subordinate(2000)
        {
             std::cout<<"\n Manager()";
        }
         Manager(int eid, std::string enm, double esal, float exp,int n,double in)
         :numberof_subordinates(n),incentiveper_subordinate(in),Employee(eid,enm,esal,exp)
        {
             std::cout<<"\n Manager(...)";
        }
        void display()
        {
            Employee::display();
            std::cout<<"\n numberof_subordinates="<<numberof_subordinates;
            std::cout<<" incentiveper_subordinate = "<<incentiveper_subordinate;
        }
        ~Manager()
        {
            std::cout<<"\n ~Manager()";
        }
        double calTotalsalary()
        {
              std::cout<<"\n Manager calTotalsalary()  ";
            return Employee::calTotalsalary()+numberof_subordinates*incentiveper_subordinate;
        }
        void calBonus()
        {
            std::cout<<"Bonus of Manager = "<<numberof_subordinates*incentiveper_subordinate;            
        }
};
//create object of manager in main()

#endif // MANAGER_H
