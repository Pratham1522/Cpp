#include "customer.h"

class date
{
   int day;
   int month;
   int year;

   public:
   date();
   date(int,int,int);

   int getDay() const { return day; }
   void setDay(int day_) { day = day_; }

   int getMonth() const { return month; }
   void setMonth(int month_) { month = month_; }

   int getYear() const { return year; }
   void setYear(int year_) { year = year_; }
   
   void accept();
   friend std::ostream& operator <<(std::ostream&,date &d);
   
};