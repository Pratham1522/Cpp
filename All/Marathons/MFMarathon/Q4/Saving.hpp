#pragma once
#include"Account.hpp"

class Saving :public Account<Saving>
{
public:
    void debitAccount(const int Accid, const int amount) override
    {
        cout << "Debit Savings\n";
    }
};

