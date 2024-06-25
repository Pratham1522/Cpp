#ifndef EMPTYCONTAINEREXCEPTION_H
#define EMPTYCONTAINEREXCEPTION_H

#include <future>
#include <string>
#include <iostream>

/*
    Create custom exceptions with parent class as std::future_error.
    How to actually throw the exception?    
            -- All future errors are primary categorized into 4 errors:
                1. broken_promise 
                2. future_already_retrieved 
                3. no_state 
                4. promise_already_satisfied 
*/

class EmptyContainerException : public std::future_error
{
    private:
    std::string _msg{""};

    public:
    EmptyContainerException() = delete;
    ~EmptyContainerException() = default;

    EmptyContainerException(const EmptyContainerException&) = delete;
    EmptyContainerException& operator=(const EmptyContainerException&) = delete;

    EmptyContainerException(EmptyContainerException&&) = default;
    EmptyContainerException& operator=(EmptyContainerException&&) = default;

    EmptyContainerException(std::string _msg, std::future_errc ec) 
                :_msg{_msg}, std::future_error(ec){};

    std::string msg() const { return _msg; }
};


#endif // EMPTYCONTAINEREXCEPTION_H
