#pragma once
#include"DB.hpp"

template <typename T>
class Account
{
    DB* db{ nullptr };
public:
    void setDB( DB* db)
    {
        ((T*)this)->db = db;
    }
    virtual void debitAccount(const int Accid,const int amount) = 0;

    void exeTask(const int Accid,const int amount)
    {
        db->OpenDB();
        ((T*)this)->debitAccount(Accid, amount);
        db->CloseDB();
    }
};
