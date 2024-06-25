#ifndef PROJECT_H
#define PROJECT_H

#include <iostream>
#include<functional>

class Project 
{
private:
    int _id{0};
    float _budget;
    std::string projectname{""};
public:
    Project() = delete; // Default constructor
    Project(const Project&) = delete; // Copy constructor
    Project& operator=(const Project&) = delete; // Copy assignment operator
    Project(Project&&) = delete; // Move constructor
    Project& operator=(Project&&) = delete; // Move assignment operator
    ~Project() = default; // Destructor

    Project(int id, float budget, std::string name);

    int id() const { return _id; }

    std::string getProjectname() const { return projectname; }
    void setProjectname(const std::string &projectname_) { projectname = projectname_; }

    float budget() const { return _budget; }
    void setBudget(float budget) { _budget = budget; }

    friend std::ostream &operator<<(std::ostream &os, const Project &rhs);
};

#endif // PROJECT_H
