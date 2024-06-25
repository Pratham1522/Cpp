#ifndef CONTAINEREMPTYEXCEPTION_H
#define CONTAINEREMPTYEXCEPTION_H

#include<stdexcept>

class ContainerEmptyException : std::exception
{
private:
    std::string _msg;
public:
    explicit ContainerEmptyException(std::string message):_msg(message) {}
    ~ContainerEmptyException() = default;
    ContainerEmptyException(const ContainerEmptyException&) = delete;
    ContainerEmptyException& operator=(const ContainerEmptyException&) = delete;
    ContainerEmptyException& operator=(const ContainerEmptyException&&) = delete;
    ContainerEmptyException(ContainerEmptyException&&) = delete;
    ContainerEmptyException() = delete;
    std::string what(){ return _msg;}
};

#endif // CONTAINEREMPTYEXCEPTION_H
