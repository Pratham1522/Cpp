#ifndef INVALIDINPUTEXCEPTION_H
#define INVALIDINPUTEXCEPTION_H

#include <future>
#include <string>

class InvalidInputException : public std::future_error
{
    private:
    std::string _msg{""};

    public:
    InvalidInputException() = delete;
    ~InvalidInputException() = default;

    InvalidInputException(const InvalidInputException&) = delete;
    InvalidInputException& operator=(const InvalidInputException&) = delete;

    InvalidInputException(InvalidInputException&&) = default;
    InvalidInputException& operator=(InvalidInputException&&) = default;

    InvalidInputException(std::string _msg, std::future_errc ec) 
                :_msg{_msg}, std::future_error(ec){};

    std::string msg() const { return _msg; }
};


#endif // INVALIDINPUTEXCEPTION_H
