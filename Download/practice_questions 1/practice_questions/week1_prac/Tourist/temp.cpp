#include <iostream>

class temp 
{
private:
    
public:
    temp() = default; // Default constructor
    temp(const temp&) = default; // Copy constructor
    temp& operator=(const temp&) = delete; // Copy assignment operator
    temp(temp&&) = delete; // Move constructor
    temp& operator=(temp&&) = delete; // Move assignment operator
    ~temp() = default; // Destructor
};