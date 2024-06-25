#ifndef BUSINESS_H
#define BUSINESS_H

#include <iostream>

class Business 
{
private:
    std::string str{""};
public:
    Business() = default; // Default constructor
    Business(const Business&) = default; // Copy constructor
    Business& operator=(const Business&) = delete; // Copy assignment operator
    Business(Business&&) = delete; // Move constructor
    Business& operator=(Business&&) = delete; // Move assignment operator
    ~Business() = default; // Destructor
    Business(std::string s):str{s}{};

    void Display()
    {
        std::cout<<str<<" ";
    }

};

#endif // BUSINESS_H
