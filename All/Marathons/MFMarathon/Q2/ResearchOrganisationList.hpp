#pragma once
#include "ResearchOrganization.hpp"

class ResearchOrganisationList 
{
    list<ResearchOrganization*> organisations;
    public:
    void AddOrganisarion(ResearchOrganization* rorg)
    {
        organisations.push_back(rorg);
    }
    friend ostream& operator<<(ostream& os, ResearchOrganisationList& rlist)
    {
        for (auto rng : rlist.organisations)
        {
            os << *rng << '\n';
        }
        return os;
    }
};
