#include "Date.h"
#include<iostream>
#include<limits>

std::ostream &operator<<(std::ostream &os, const Date &rhs) {
    os << "_day: " << rhs._day
       << " _month: " << rhs._month
       << " _year: " << rhs._year;
    return os;
}

Date::Date(int dd, int mm, int yyyy)
    :_day(dd), _month(mm), _year(yyyy)
{
}

void Date::accept()
{
    int year,month,day;
    std::cout<<"enter year: ";
    std::cin>>year;
    setYear(year); 
    try{
        std::cout<<"enter month: ";
        std::cin>>month;
        if(month<0 && month>13) throw 0;
        else{
            setMonth(month);
        }
    }
    catch(int temp){
        std::cout<<"enter coorect month only!\n";
    }
    try{
        std::cout<<"enter day: ";
        std::cin>>day;
        if(month == 2){
            if(day>0 && day<30) setDay(day);
            else{
                throw 0;
            }
        }
        else if(month==1 || month==3 || month==5 || month==7 || month==8 || month==10 || month==12){
            if(day>0 && day<=31){
                setDay(day);
            }
            else{
                throw 0;
            }
        }
        else{
            if(day>0 && day<=30){
                setDay(day);
            }
            else{
                throw 0;
            }
        }
    }
    catch(int x){
        std::cout<<"enter correct day\n";
    }
}
