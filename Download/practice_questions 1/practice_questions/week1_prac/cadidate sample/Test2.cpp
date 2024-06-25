#include "Test2.h"
std::ostream &operator<<(std::ostream &os, const Test2 &rhs) {
    os << "_contestID: " << rhs._contestID
       << " _date: " << rhs._date
       << " _maxMarks: " << rhs._maxMarks
       << " _marksSecured: " << rhs._marksSecured;
    return os;
}

void Test2::accept()
{
    int id;
    std::string date;
    int totalmarks;
    std::cout<<"Enter contestid: ";
    std::cin>>id;
    std::cout<<"Enter date of exam: ";
    std::cin>>date;
    std::cout<<"Enter marks scored in Test 2: ";
    std::cin>>totalmarks;
    setContestID(id);
    setDate(date);
    setMarksSecured(totalmarks);
}