#pragma once
#include"customer.h"
#include"date.h"
#include"bill.h"
class bill
{
private:
    int bill_number;
    int bill_amount;
    customer customer_info;
    Date bill_date;

public:
    bill();

    void setBillNumber(int bn);
    void setBillAmount(int ba);

    void getAll();

    int getBill()const;

    void accept();

    ~bill();
};
