#ifndef PERMIT_H
#define PERMIT_H
#include<iostream>
#include "Own.h"

class Permit
{
private:
    std::string _serialNumber{0};
    Own _permitType{0};
    int _permitDuration{0};
public:
    Permit() = default;
    ~Permit() = default;
    Permit(std::string serialnum, Own type, int duration);

    std::string serialNumber() const { return _serialNumber; }

    void setSerialNumber(const std::string &serialNumber) { _serialNumber = serialNumber; }

    Own permitType() const { return _permitType; }
    void setPermitType(const Own &permitType) { _permitType = permitType; }

    int permitDuration() const { return _permitDuration; }
    void setPermitDuration(int permitDuration) { _permitDuration = permitDuration; }

    friend std::ostream &operator<<(std::ostream &os, const Permit &rhs);
};

class sample{
    private:
        int st {0};
    public:
        sample() = default;
        int getst() const { return st; }
        friend std::ostream &operator<<(std::ostream& os, const sample &rhs);
};

#endif // PERMIT_H
