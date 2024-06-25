#include <iostream>
#include "billnbudget.h"

int main()
{
    Electricity user1;    //create obj
    user1.Accept();         //accept data from user
    user1.Display();        //display data
    double bill=user1.calculateElectricityBill();   //calc bill
    std::cout << "\n This month Electricity Bill is :" << bill << "\n";

}