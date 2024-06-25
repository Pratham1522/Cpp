#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include "Passenger.h"
#include<iostream>
#include<functional>
#include<vector>
#include<memory>
#include<list>

using Container = std::vector<std::shared_ptr<Passenger>>;
using TicketContainer = std::list<Ticket>;

void CreateObjects(Container& data,TicketContainer& tickets);

#endif // FUNCTIONALITIES_H
