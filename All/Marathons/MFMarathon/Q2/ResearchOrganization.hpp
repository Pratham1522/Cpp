#pragma once
#include "Missionlist.hpp"

class ResearchOrganization
{
    Missionlist missions;
    string Name;
public:
    ResearchOrganization(const string Name) :Name(Name)
    {
    }
    void AddMission(Mission* mission)
    {
        missions.push_back(mission);
    }
    friend ostream& operator<<(ostream& os, ResearchOrganization& org)
    {
        os << "\t\t" << org.Name << '\n' << org.missions;
        return os;
    }

};
