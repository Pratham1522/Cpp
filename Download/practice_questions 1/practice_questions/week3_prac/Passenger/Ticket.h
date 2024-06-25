#ifndef TICKET_H
#define TICKET_H

#include <iostream>

class Ticket 
{
private:
    float _tax{0.0f};
public:
    Ticket() = default; // Default constructor
    Ticket(const Ticket&) = delete; // Copy constructor
    Ticket& operator=(const Ticket&) = delete; // Copy assignment operator
    Ticket(Ticket&&) = default; // Move constructor
    Ticket& operator=(Ticket&&) = default; // Move assignment operator
    ~Ticket() = default; // Destructor
    Ticket(float tax);

    float tax() const { return _tax; }
    void setTax(float tax) { _tax = tax; }

    friend std::ostream &operator<<(std::ostream &os, const Ticket &rhs);
};

#endif // TICKET_H
