#include "Project.h"

Project::Project(int id, float budget, std::string name)
    :_id(id), projectname(name), _budget(budget)
{
}
std::ostream &operator<<(std::ostream &os, const Project &rhs) {
    os << "_id: " << rhs._id
    << "budget: " << rhs._budget
    << " projectname: " << rhs.projectname;
    return os;
}

//why do we do return by reference for op overloading??