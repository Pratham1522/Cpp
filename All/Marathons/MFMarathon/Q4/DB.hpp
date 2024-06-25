#pragma once
#include<iostream>
using std::cout;

class DB
{
public:
    virtual void OpenDB() = 0;
    virtual void CloseDB() = 0;
    operator DB* ()
    {
        return this;
    }
};
