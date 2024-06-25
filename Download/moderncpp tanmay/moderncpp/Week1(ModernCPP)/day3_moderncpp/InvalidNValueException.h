#ifndef INVALIDNVALUEEXCEPTION_H
#define INVALIDNVALUEEXCEPTION_H

#include<stdexcept>
#include<cstring>

class InvalidNValueException : std::exception
{
private:
    char  *_msg;
public:
    explicit InvalidNValueException(const char* message){
        _msg = new char[strlen(message)+1];
        strcpy(_msg,message);
    }
    ~InvalidNValueException() = default;
    InvalidNValueException(const InvalidNValueException&) = delete;
    InvalidNValueException& operator=(const InvalidNValueException&) = delete;
    InvalidNValueException& operator=(const InvalidNValueException&&) = delete;
    InvalidNValueException(const InvalidNValueException&&) = delete;
    InvalidNValueException() = delete;
    std::string what(){ return _msg;}
};

#endif // INVALIDNVALUEEXCEPTION_H
