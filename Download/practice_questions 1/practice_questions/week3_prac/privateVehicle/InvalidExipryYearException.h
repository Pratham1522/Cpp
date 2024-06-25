#ifndef INVALIDEXIPRYYEAREXCEPTION_H
#define INVALIDEXIPRYYEAREXCEPTION_H

#include <stdexcept>
#include <string>
#include <cstring>
class InvalidExipryYearException : public std::exception
{
    std::string _msg;

public:
    InvalidExipryYearException() = delete;

    InvalidExipryYearException(const InvalidExipryYearException &) = delete; // disabled copy constructor

    InvalidExipryYearException(InvalidExipryYearException &&) = delete; // disabled move constructor brand new in C++11

    InvalidExipryYearException &operator=(const InvalidExipryYearException &) = delete; // disabled assignment operator
    InvalidExipryYearException &operator=(InvalidExipryYearException &&) = delete;      // disabled assignment move operator brand new in C++11

    ~InvalidExipryYearException() = default;
    InvalidExipryYearException(std::string msg) : _msg(msg)
    {
    }
    virtual const char *what() const _GLIBCXX_TXN_SAFE_DYN _GLIBCXX_NOTHROW override
    {
        return _msg.c_str();
    }

    
};

#endif // INVALIDEXIPRYYEAREXCEPTION_H
