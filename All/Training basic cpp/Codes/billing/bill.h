#include "date.h"

class bill
{
   int billnumber;
   customer customerinfo;
   date billdate;
   int billamount;

   public:
   bill();
   bill(int,const char*,int,int,int,int);
   void accept();
   friend std::ostream& operator<<(std::ostream&,bill &other);
   ~bill();

   int getBillnumber() const { return billnumber; }
   void setBillnumber(int billnumber_) { billnumber = billnumber_; }

   int getBillamount() const { return billamount; }
   void setBillamount(int billamount_) { billamount = billamount_; }

   bool find(const char*);


   
};

void totalamount(bill []);