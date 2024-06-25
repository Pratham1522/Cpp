#pragma once
#include "Scientist.hpp"
using std::list;

class ScientistList :public list<Scientist*>
{
public:
    friend ostream& operator<<(ostream& os, ScientistList& sList)
    {
        for (auto scientist : sList)
        {
            os << *scientist ;
        }
        return os;
    }
};
