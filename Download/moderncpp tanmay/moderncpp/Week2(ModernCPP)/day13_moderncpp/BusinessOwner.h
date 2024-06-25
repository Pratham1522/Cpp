#ifndef BUSINESSOWNER_H
#define BUSINESSOWNER_H

#include <iostream>

class BusinessOwner 
{
private:
    std::string _name;
    float _revenue;
    float _expenses;
    float _profits;
public:
    BusinessOwner() = default; // Default constructor
    BusinessOwner(const BusinessOwner&) = delete; // Copy constructor
    BusinessOwner& operator=(const BusinessOwner&) = delete; // Copy assignment operator
    BusinessOwner(BusinessOwner&&) = delete; // Move constructor
    BusinessOwner& operator=(BusinessOwner&&) = delete; // Move assignment operator
    ~BusinessOwner() = default; // Destructor

    BusinessOwner(std::string name, float revenue, float expenses): _name(name), _revenue(revenue), _expenses(expenses){
        _profits = _revenue - _expenses;
    }

    void payTax(){
        if(_profits<0){
            std::cout<<"no tax for you!!\n";
        }
        else if(_profits>=50000.0f && _profits<=100000.0f){
            std::cout<<"20% tax for you!!\n";
        }
        else{
            std::cout<<"31% tax for you!!\n";
        }
    }

    std::string name() const { return _name; }
    void setName(const std::string &name) { _name = name; }

    float revenue() const { return _revenue; }
    void setRevenue(float revenue) { _revenue = revenue; }

    float expenses() const { return _expenses; }
    void setExpenses(float expenses) { _expenses = expenses; }

    float profits() const { return _profits; }
};

#endif // BUSINESSOWNER_H
