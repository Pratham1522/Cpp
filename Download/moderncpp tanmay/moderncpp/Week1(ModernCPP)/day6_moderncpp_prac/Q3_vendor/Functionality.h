#ifndef FUNCTIONALITY_H
#define FUNCTIONALITY_H
#include "Vendor.h"
#include "Customer.h"

using Container = std::vector<Account*>;

void CreateObjects(Container &data);

void DeleteObjects(Container &data);

#endif // FUNCTIONALITY_H

