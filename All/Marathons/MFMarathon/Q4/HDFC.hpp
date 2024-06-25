#pragma once
#include"DB.hpp"

class HDFC :public DB
{
public:
    void OpenDB() override
    {
        cout << "HDFC DB OPENED\n";
    }
    void CloseDB() override
    {
        cout << "HDFC DB CLOSED\n";
    }
};
