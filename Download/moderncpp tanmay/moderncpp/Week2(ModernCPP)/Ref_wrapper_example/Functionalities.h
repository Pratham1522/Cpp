#ifndef FUNCTIONALITIES_H
#define FUNCTIONALITIES_H

#include "Bill.h"
#include<memory>
#include "Invoice.h"
#include<vector>
#include<functional>

using Container = std::vector<std::shared_ptr<Bill>>;
using InvoiceContainer = std::vector<Invoice>;


void CreateObjects(Container &data, InvoiceContainer& inv);

extern std::function<float(Container&)>HighestBillAmount;

extern std::function<Container(Container&,int)> FindNInstance;

extern std::function<Container(Container&,int)> BindNInstace;

#endif // FUNCTIONALITIES_H
