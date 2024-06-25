#ifndef SAMPLE_H
#define SAMPLE_H

#include <iostream>

class sample 
{
private:
    int x{5};
public:
    sample() = default; // Default constructor
    sample(const sample&) = default; // Copy constructor
    sample& operator=(const sample&) = delete; // Copy assignment operator
    sample(sample&&) = default; // Move constructor
    sample& operator=(sample&&) = delete; // Move assignment operator
    ~sample() = default; // Destructor
    sample(int a): x(a){}

    friend std::ostream &operator<<(std::ostream &os, const sample &rhs) {
        os << "x: " << rhs.x;
        return os;
    }
};

#endif // SAMPLE_H
