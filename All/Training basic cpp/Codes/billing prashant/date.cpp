#include "date.h"
#include"customer.h"
#include<iostream>
Date::Date()
{
    std::cout<<"Date class constructor called!!\n";
    date=1;
    month=1;
    year = 2024;

}

Date::Date(int dd, int mm, int yy)
{
    date = dd;
    month=mm;
    year=yy;
}

bool Date::isValidDate()
{
    if(month == 1 || month==3 || month==5 || month==7 || month==8 || month==10 || month==12){
        if(date > 31){
            return false;
        }
    }

    else if(month == 2){
        if(year % 4 == 0){
            if(date > 29){
                return false;
            }
        }
        else{
            return false;
        }
    }
    else{
        if(date > 30){
            return false;
        }
    }
    return true;
}

bool Date::isValidMonth()
{
    if(month < 1 || month > 12){
        return false;
    }
    return true;
}

void Date::setDate(int dd,int mm, int yy)
{
    date = dd;
    month=mm;
    year=yy;
}



void Date::accept()
{
    
    std::cout<<"Enter the month : ";
    std::cin >> month;

    std::cout<<"Enter the date : ";
    std::cin >> date;

    std::cout<<"Enter the year : ";
    std::cin >> year;

    
}

void Date::getAll()
{
    if(isValidDate() && isValidMonth()){
        std::cout<<"Date is : "<< date << "/"<<month << "/" << year << "\n";
    }
    else{
        std::cout<<"Date is not valid !!\n";
    }
}

// std::ostream& operator<<(std::ostream &os, Date &other)
// {
//     os << other.date <<'\n';
//     os<<other.month<<'\n';
//     os<<other.year<<'\n';
//     return os;
// }






// void Date::setYear(int yy)
// {
//     if(isValidYear(yy)){
//         year = yy;
//     }
//     else{
//         std::cout<<"Year is not valid\n";
//     }
// }





// bool Date::isValidYear(int year)
// {
//     if(year < 2024){
//         return false;
//     }
//     return true;
// }
