#include "Owner.h"

Owner::Owner(std::string name)
    :_registeredname(name)
{
}
std::ostream &operator<<(std::ostream &os, const Owner &rhs) {
    os << "_registeredname: " << rhs._registeredname;
    return os;
}
