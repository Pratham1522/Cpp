#ifndef CONDITIONDOESNOTMATCHEXCEPTION_H
#define CONDITIONDOESNOTMATCHEXCEPTION_H

#include <string>
#include <future>

class ConditionDoesNotMatchException : public std::future_error
{
    private:
    std::string _msg{""};

    public:
    ConditionDoesNotMatchException() = delete;
    ~ConditionDoesNotMatchException() = default;

    ConditionDoesNotMatchException(const ConditionDoesNotMatchException&) = delete;
    ConditionDoesNotMatchException& operator=(const ConditionDoesNotMatchException&) = delete;

    ConditionDoesNotMatchException(ConditionDoesNotMatchException&&) = default;
    ConditionDoesNotMatchException& operator=(ConditionDoesNotMatchException&&) = default;

    ConditionDoesNotMatchException(std::string _msg, std::future_errc ec) 
                :_msg{_msg}, std::future_error(ec){};

    std::string msg() const { return _msg; }
};


#endif // CONDITIONDOESNOTMATCHEXCEPTION_H
