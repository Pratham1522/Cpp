#ifndef OWNER_H
#define OWNER_H

#include <iostream>

class Owner 
{
private:
    std::string _registeredname{""};
    
public:
    Owner() = default; // Default constructor
    Owner(const Owner&) = default; // Copy constructor
    Owner& operator=(const Owner&) = delete; // Copy assignment operator
    Owner(Owner&&) = delete; // Move constructor
    Owner& operator=(Owner&&) = delete; // Move assignment operator
    ~Owner() = default; // Destructor

    Owner(std::string name);

    std::string registeredname() const { return _registeredname; }
    void setRegisteredname(const std::string &registeredname) { _registeredname = registeredname; }

    friend std::ostream &operator<<(std::ostream &os, const Owner &rhs);
};

#endif // OWNER_H
