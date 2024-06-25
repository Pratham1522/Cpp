#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>

class Account 
{
private:
    int _accountId{0};
    std::string _accoutnName{"abc"};

public:
    Account() = default; // Default constructor
    Account(const Account&) = default; // Copy constructor
    Account& operator=(const Account&) = delete; // Copy assignment operator
    Account(Account&&) = delete; // Move constructor
    Account& operator=(Account&&) = delete; // Move assignment operator
    ~Account() = default; // Destructor
    Account(int id,std::string name);
    virtual void registerstatus()=0;

    int accountId() const { return _accountId; }

    std::string accoutnName() const { return _accoutnName; }
    void setAccoutnName(const std::string &accoutnName) { _accoutnName = accoutnName; }
};

#endif // ACCOUNT_H
