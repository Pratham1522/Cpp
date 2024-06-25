#ifndef TEST2_H
#define TEST2_H
#include<iostream>

class Test2
{
private:
    int _contestID {0};
    std::string _date {"00/00/0000"};
    const int _maxMarks {100};
    int _marksSecured {0};
public:
    Test2() = default;
    ~Test2() = default;

    int contestID() const { return _contestID; }
    void setContestID(int contestID) { _contestID = contestID; }

    std::string date() const { return _date; }
    void setDate(const std::string &date) { _date = date; }

    int marksSecured() const { return _marksSecured; }
    void setMarksSecured(int marksSecured) { _marksSecured = marksSecured; }

    friend std::ostream &operator<<(std::ostream &os, const Test2 &rhs);
    
    void accept();
};

#endif // TEST2_H
