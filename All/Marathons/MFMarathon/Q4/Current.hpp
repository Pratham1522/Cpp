#pragma once
#include"Account.hpp"

class Current :public Account<Current>
{
public:
    void debitAccount(const int Accid, const int amount) override
    {
        cout << "Debit Current\n";
    }
};
