#pragma once
#include<iostream>
#include<string>
#include<list>
using std::cout;
using std::string;
using std::ostream;


class Scientist
{
    string _name;
public:
    Scientist(const string name) :_name(name) 
    {
    }
    friend ostream& operator<<(ostream& os, Scientist& Sci)
    {
        os << "\t\t\t\t" << Sci._name << '\n';
        return os;
    }
};
