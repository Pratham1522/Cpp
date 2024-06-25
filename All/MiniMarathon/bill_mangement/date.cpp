#include "date.h"

Date::Date()
{
    day = 1;
    month = 1;
    year = 2024;
}

Date::Date(int d, int m, int y)
{
    if(isValiddate(d,m,y)){
    day=d;
    month=m;
    year=y;
    }
}

void Date::setDate(int d,int m,int y) {
    int day=d;
    int month=m;
    int year=y;
}

int Date::getDay() const 
{ 
    return day; 
}
void Date::setDay(int day_) 
{   if(isValiddate(day_,getMonth(),getYear())){
    day = day_; 
    }
}

int Date::getMonth() const 
{ 
    return month; 
}
void Date::setMonth(int month_) 
{ 
    if(isValiddate(getDay(),month_,getYear())){
        month = month_; 
    }
}

int Date::getYear() const 
{ 
    return year; 
}
void Date::setYear(int year_) 
{
    if(isValiddate(getDay(),getMonth(),year_)){
        year = year_; 
    }
}

bool Date::isValiddate(int d, int m, int y)
{
    if(d<1 || m<1 || 12<m || 31<d)
        return false;
    if(m==2){
        if((y%4==0 && y%100!=0) ||(y%400==0)){
            if(d>29){return false;}                
        }       
        else if(d>28)   {return false;} 
    }    
    if(m==2 || m==4 || m==6 ||m==9 ||m==11){
        if(30<d)
            return false;
    }
    return true;   
}

void Date::accept()
{
    int d;
    int m; 
    int y;
    std::cout << "Enter Day: ";
    std::cin>>d;
    std::cout << "Enter Month: ";
    std::cin>>m;
    std::cout << "Enter Year: ";
    std::cin>>y;
    if(isValiddate(d,m,y)){
        setDate(d,m,y);
    }
    else{
        std::cout<<"Please Enter valid date \n";
        accept();
    }
}

std::ostream &operator<<(Date &obj, std::ostream &o)
{
    // TODO: insert return statement here
    o<<"Date is :"<<obj.day<<"/"<<obj.month<<"/"<<obj.year<<"\n";
    return o;
}
