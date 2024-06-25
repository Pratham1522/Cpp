#include "Functionalities.h"

void CreateObjects(Container &data, TicketContainer &tickets)
{
    tickets.push_back(Ticket(120.0f,TicketType::A));
    tickets.push_back(Ticket(100.0f,TicketType::B));
    tickets.push_back(Ticket(10.0f,TicketType::C));
    TicketContainer::iterator itr = tickets.begin();
    data.push_back(std::make_shared<Passenger>(1,"tanmay",22,*itr++,100.0f));
    data.push_back(std::make_shared<Passenger>(2,"john",22,*itr++,70.0f));
    data.push_back(std::make_shared<Passenger>(3,"tan",22,*itr++,50.0f));
}
