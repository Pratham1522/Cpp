#ifndef TICKET_H
#define TICKET_H

#include <iostream>
#include "TicketType.h"

class Ticket 
{
private:
    float _tax{0.0f};
    TicketType _type;
public:
    Ticket() = default; // Default constructor
    Ticket(const Ticket&) = delete; // Copy constructor
    Ticket& operator=(const Ticket&) = delete; // Copy assignment operator
    Ticket(Ticket&&) = default; // Move constructor
    Ticket& operator=(Ticket&&) = delete; // Move assignment operator
    ~Ticket() = default; // Destructor

    Ticket(float tx,TicketType type);

    float tax() const { return _tax; }
    void setTax(float tax) { _tax = tax; }

    TicketType type() const { return _type; }
    void setType(const TicketType &type) { _type = type; }

    friend std::ostream &operator<<(std::ostream &os, const Ticket &rhs);
};

#endif // TICKET_H
