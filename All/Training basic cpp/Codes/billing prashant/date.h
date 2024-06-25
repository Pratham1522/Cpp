#pragma once
#include<iostream>
#include"customer.h"
class Date{
    
private:
    int date;
    int month;
    int year;
    // customer c1;

public:
    Date();

    Date(int dd, int mm, int yy);

    bool isValidDate();

    void setDate(int dd, int mm, int yy);

    bool isValidMonth();

    void accept();

    void getAll();

    friend std::ostream operator<<(std::ostream&,Date&);

};
