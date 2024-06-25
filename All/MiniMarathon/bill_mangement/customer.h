#pragma once
#include<iostream>

class Customer{
    char* customername;

    public:
    Customer();
    Customer(char* name);
    Customer(Customer &obj1);

    char* getCustomername() const;
    void setCustomername(char* customername_);
    
    void accept();
    friend std::ostream& operator<<(Customer &obj,std::ostream &o);
    ~Customer();
};

