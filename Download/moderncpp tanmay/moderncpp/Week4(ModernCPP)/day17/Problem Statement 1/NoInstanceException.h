#ifndef NOINSTANCEEXCEPTION_H
#define NOINSTANCEEXCEPTION_H

#include <string>
#include <future>

class NoInstanceException : public std::future_error
{
    private:
    std::string _msg{""};

    public:
    NoInstanceException() = delete;
    ~NoInstanceException() = default;

    NoInstanceException(const NoInstanceException&) = delete;
    NoInstanceException& operator=(const NoInstanceException&) = delete;

    NoInstanceException(NoInstanceException&&) = default;
    NoInstanceException& operator=(NoInstanceException&&) = default;

    NoInstanceException(std::string _msg, std::future_errc ec) 
                :_msg{_msg}, std::future_error(ec){};

    std::string msg() const { return _msg; }
};

#endif // NOINSTANCEEXCEPTION_H
