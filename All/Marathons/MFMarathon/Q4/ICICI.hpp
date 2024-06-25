#pragma once
#include"DB.hpp"

class ICICI :public DB
{
public:
    void OpenDB() override
    {
        cout << "ICICI DB OPENED\n";
    }
    void CloseDB() override
    {
        cout << "ICICI DB CLOSED\n";
    }
};
