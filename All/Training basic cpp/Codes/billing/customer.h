#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <cstring>

class customer
{
   char *customername;

   public:
   customer();
   customer(const char *);
   customer(customer &);

   char *getCustomername() const { return customername; }
   void setCustomername(char *customername_) { strcpy(customername,customername_); }

   void accept();
   friend std::ostream& operator <<(std::ostream&, customer&);
   ~customer();
   
};

#endif // CUSTOMER_H
