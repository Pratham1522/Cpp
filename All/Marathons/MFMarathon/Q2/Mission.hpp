#pragma once
#include "ScientistList.hpp"

class Mission
{
    ScientistList scientists;
    string name;
public:
    Mission(string name) :name(name)
    {
    }
    void AddScientist(Scientist* Sci)
    {
        scientists.push_back(Sci);
    }
    friend ostream& operator<<(ostream& os, Mission& mission)
    {
        os << "\t\t\t" << mission.name << '\n' << mission.scientists;
        return os;
    }

};
