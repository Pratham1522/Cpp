#ifndef CANDIDATE_H
#define CANDIDATE_H
#include<iostream>


enum class JobApplied{
    CLERK,
    MANAGER,
    ENGINEER
};

class Candidate
{
private:
    std::string _candidateName {""};
    int _candidateID {0};

public:
    Candidate() = default;
    ~Candidate() = default;
    Candidate(std::string name, int id);
    Candidate(const Candidate&rhs);

    std::string candidateName() const { return _candidateName; }
    void setCandidateName(const std::string &candidateName) { _candidateName = candidateName; }

    void setCandidateID(int candidateID) { _candidateID = candidateID; }

    int candidateID() const { return _candidateID; }
    
    void accept();

    friend std::ostream &operator<<(std::ostream &os, const Candidate &rhs);
    
};

#endif // CANDIDATE_H
