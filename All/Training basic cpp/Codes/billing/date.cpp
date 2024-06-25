#include "date.h"

date::date():day(10),month(02),year(2001)
{

}

date::date(int num,int num1,int num2):day(num),month(num1),year(num2)
{
   
}

void date::accept()
{
    std::cout<<"Enter day  "<<std::endl;
    std::cin>>day;
    std::cout<<"Enter month"<<std::endl;
    std::cin>>month;
    std::cout<<"Enter year "<<std::endl;
    std::cin>>year;
}

std::ostream& operator<<(std::ostream& out,date &other)
{
    out<<"day   "<<std::endl;
    out<<other.day;
    out<<"month "<<std::endl;
    out<<other.month;
    out<<"year  "<<std::endl;
    out<<other.year;
    return out;
}