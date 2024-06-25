#include"Salesperson.h"
Salesperson::Salesperson():salesamount(5000),commrate(0.05)
{
      std::cout << "\n Salesperson() called ";
}
Salesperson::Salesperson(int eid,std::string nm,double esal,
    float exp,double samt,double cr): Employee(eid,nm,esal,exp)
     ,salesamount(samt),commrate(cr)
{
      std::cout << "\n Salesperson(...) called ";    
}
void Salesperson::display()
{
    Employee::display();
    std::cout<<"salesamount ="<<salesamount<<" commrate="<<commrate<<"\n";
}
double Salesperson::calTotalsalary()
{
    std::cout<<"\n Salesperson calTotalsalary() fun \n";
    return Employee::calTotalsalary()+salesamount*commrate;
}
Salesperson::~Salesperson()
{
    std::cout << "\n ~Salesperson() called ";
}

