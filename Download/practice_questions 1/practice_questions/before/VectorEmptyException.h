#ifndef VECTOREMPTYEXCEPTION_H
#define VECTOREMPTYEXCEPTION_H

#include <iostream>

class VectorEmptyException :public std::exception
{
private:
    std::string _msg;
public:
    VectorEmptyException() = default; // Default constructor
    VectorEmptyException(const VectorEmptyException&) = default; // Copy constructor
    VectorEmptyException& operator=(const VectorEmptyException&) = delete; // Copy assignment operator
    VectorEmptyException(VectorEmptyException&&) = delete; // Move constructor
    VectorEmptyException& operator=(VectorEmptyException&&) = delete; // Move assignment operator
    ~VectorEmptyException()=default;// Destructor
    
    VectorEmptyException(std::string msg) :_msg(msg)
    {
    }
    std::string what(){
        return _msg;
    }
};

#endif // VECTOREMPTYEXCEPTION_H
