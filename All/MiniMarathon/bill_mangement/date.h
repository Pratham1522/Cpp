#pragma once
#include<iostream>

class Date{
    int day;
    int month;
    int year;

    public:
    Date();
    Date(int d,int m,int y);

    void setDate(int d,int m,int y);
    int getDay() const ;
    void setDay(int day_) ;

    int getMonth() const ;
    void setMonth(int month_) ;

    int getYear() const ;
    void setYear(int year_) ;
    bool isValiddate(int d,int m,int y);
    
    void accept();

    friend std::ostream& operator<<(Date &obj,std::ostream &o);
};