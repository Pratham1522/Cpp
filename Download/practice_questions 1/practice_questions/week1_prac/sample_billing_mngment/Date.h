#ifndef DATE_H
#define DATE_H
#include <ostream>

class Date
{
private:
    int _day {0};
    int _month {0};
    int _year {0};
public:
    Date() = default;
    ~Date() = default;
    Date(const Date &rhs) = default;
    Date &operator=(const Date &rhs) = default;
    Date(int dd, int mm, int yyyy);

    int year() const { return _year; }
    void setYear(int year) { _year = year; }

    int month() const { return _month; }
    void setMonth(int month) { _month = month; }

    int day() const { return _day; }
    void setDay(int day) { _day = day; }

    friend std::ostream &operator<<(std::ostream &os, const Date &rhs);

    void accept();
    
};

#endif // DATE_H
