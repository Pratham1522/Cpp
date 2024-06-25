#pragma once
#include<iostream>
#include"customer.h"
#include"date.h"

class Bill{
    int billnumber;
    Customer customerinfo;
    Date billdate;
    int billamount;

public:
    Bill();

    int getBillnumber() const ;
    void setBillnumber(int billnumber_) ;


    void accept();
    friend std::ostream& operator<<(std::ostream &o, Bill &obj);
    ~Bill();


};
