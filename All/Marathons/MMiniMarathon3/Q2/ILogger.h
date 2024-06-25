#pragma once
#include<iostream>
#include<string>
using std::string;

class ILogger 
{
    public:
    virtual void log(string) = 0;
};
