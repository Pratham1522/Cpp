#include "Car.h"

Car::Car(int num, std::shared_ptr<Vehicle> sptr)
    :_num(num),_sptr(sptr)
{
}
std::ostream &operator<<(std::ostream &os, const Car &rhs) {
    os << "_num: " << rhs._num;
    os<<"sptr: "<<*rhs._sptr;
    return os;
}
