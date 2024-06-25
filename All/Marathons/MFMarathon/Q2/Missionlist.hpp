#pragma once
#include "Mission.hpp"

class Missionlist :public list<Mission*>
{
public:
    friend ostream& operator<<(ostream& os, Missionlist& mlist)
    {
        for (auto rng : mlist)
        {
            os << *rng;
        }
        return os;
    }
};
