#pragma once
#include "ResearchOrganisationList.hpp"

void start()
{
    Mission* mission;
    ResearchOrganization* org;

    ResearchOrganisationList ROList;
    ROList.AddOrganisarion(org=new ResearchOrganization("ISRO"));
    org->AddMission(mission = new Mission("Chandrayaan 1"));
    mission->AddScientist(new Scientist("a1"));
    mission->AddScientist(new Scientist("a2"));
    mission->AddScientist(new Scientist("a3"));

    org->AddMission(mission = new Mission("Chandrayaan 2"));
    mission->AddScientist(new Scientist("b1"));
    mission->AddScientist(new Scientist("b2"));
    mission->AddScientist(new Scientist("b3"));

    org->AddMission(mission = new Mission("Chandrayaan 3"));
    mission->AddScientist(new Scientist("c1"));
    mission->AddScientist(new Scientist("c2"));
    mission->AddScientist(new Scientist("c3"));

    ROList.AddOrganisarion(org=new ResearchOrganization("CSIR"));
    org->AddMission(mission = new Mission("economic"));
    org->AddMission(mission = new Mission("environmental"));
    org->AddMission(mission = new Mission("societal"));

    ROList.AddOrganisarion(org=new ResearchOrganization("DRDO"));
    org->AddMission(mission = new Mission("Aeronautics"));
    org->AddMission(mission = new Mission("Armaments"));
    org->AddMission(mission = new Mission("Avionics Radars"));

    ROList.AddOrganisarion(org=new ResearchOrganization("ICMR"));
    org->AddMission(mission = new Mission("Tribal Health"));
    org->AddMission(mission = new Mission("Disease Informatics"));
    mission->AddScientist(new Scientist("s1"));
    mission->AddScientist(new Scientist("s2"));
    mission->AddScientist(new Scientist("s3"));
    mission->AddScientist(new Scientist("s4"));

    org->AddMission(mission = new Mission("Immunohaemotology"));

    ROList.AddOrganisarion(org=new ResearchOrganization("BARC"));
    org->AddMission(mission = new Mission("Thorium fuel cycle"));
    org->AddMission(mission = new Mission("Nuclear waste management"));
    org->AddMission(mission = new Mission("Fuel Fabriction"));

    org->AddMission(mission = new Mission("Radiochemical Science"));
    mission->AddScientist(new Scientist("r1"));
    mission->AddScientist(new Scientist("r2"));
    mission->AddScientist(new Scientist("r3"));

    cout<< ROList;
}
