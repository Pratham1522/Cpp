#pragma once
#include<iostream>
class customer{
private:
    char* customer_name;

public:
    customer();

    customer(const char* name);

    void setName(const char* name);

    void getName() const;

    void accept();

    friend std::ostream& operator<<(std::ostream&, customer&);

    ~customer();
};
