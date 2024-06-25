#include "Salesperson.h"
#include "Manager.h"

int main()
{
// To calculate Commission amount of a Salesperson exclude basic salary

// use dynamic_cast only for down cast
// dynamic_cast can convert base class pointer to derive class pointer safely
/*
    if dynamic_cast fails to convert it returns null pointer/zero
    if it succeeds then it returns pointer to derive type.
*/
Employee *ptr = new Salesperson(203, "Soham", 55000, 4.5, 100000, 3);
// typeid operator
std::cout<<"\n ----------- Type of *ptr = "<<typeid(ptr).name();
if(typeid(*ptr) == typeid(Salesperson))
{
    Salesperson *sptr=dynamic_cast<Salesperson*>(ptr);//down cast
    std::cout<<"sptr ="<< sptr;
    if(sptr==0)
        std::cout<<"\n you are in wrong place ";
    else
        sptr->calCommission();
}
else if( typeid(*ptr) == typeid(Manager))
{
    Manager *m=dynamic_cast<Manager*>(ptr);
    m->calBonus();
}
else 
    std::cout<<"\n sorry unable to find type" ;
//virtual function pointer is created per object
// vtable is created per class and it ia static array 
// vptr is initialized in constructor
// constructor cannot be virtual
// but destructor must be virtual to call appropriate destructor from hierarchy 
//function overriding
// Use virtual keyword only for base class fun not needed for derived class function
// virtual keyword is used in declaration of the function not the definition.
//virtual fun must be member fun-
// cannot static/global fun
//virtual funcs are used achieve run time polymorphism
/*
  dynamic polymorphism/late binding
*/

    // Salesperson sp(203, "Soham", 55000, 4.5, 100000, 0.04);
    // Employee *ep = &sp;
    // std::cout << "\n total salary = " << ep->calTotalsalary() << "\n";

    // Employee *ptr = new Salesperson(203, "Soham", 55000, 4.5, 100000, 0.04);
    // std::cout << "\n total salary = " << ptr->calTotalsalary() << "\n";
    // delete ptr;

    // ptr = new Manager(501, "Yash", 68000, 6.5, 10, 5000);
    // std::cout << "\n total salary = " << ptr->calTotalsalary() << "\n";
    // delete ptr;
}