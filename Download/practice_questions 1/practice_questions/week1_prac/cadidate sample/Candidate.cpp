#include "Candidate.h"
std::ostream &operator<<(std::ostream &os, const Candidate &rhs) {
    os << "_candidateName: " << rhs._candidateName
       << " _candidateID: " << rhs._candidateID;
    return os;
}

Candidate::Candidate(std::string name, int id)
    :_candidateName(name), _candidateID(id)
{
}

Candidate::Candidate(const Candidate &rhs)
{

}

void Candidate::accept()
{
    int id;
    std::string name;
    std::cout<<"Enter name of candidate: ";
    std::cin>>name;
    setCandidateName(name);
    std::cout<<"Enter id of candidate: ";
    std::cin>>id;
    setCandidateID(id);
    int job;
    std::cout<<"Enter job applied: ";
    std::cin>>job;
}
