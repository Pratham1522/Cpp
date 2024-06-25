#include <iostream>
#include <string>
#include <vector>
#include <tuple>
using std::cout;
using std::ostream;
using std::vector;
using std::tuple;

class CComplex
{
    double real_part {0.0};
    double img_part {0.0};

    public:
    CComplex(double real,double img):real_part(real),img_part(img)
    {

    }
    CComplex operator+(const CComplex& par) const
    {
        return CComplex(this->real_part+ par.real_part , this->img_part+par.img_part);
    }
    CComplex operator+ (double par) const
    {
        return CComplex(this->real_part,this->img_part+par);
    }
    friend CComplex operator+(double val,const CComplex &par)
    {
        return CComplex(par.real_part+val,par.img_part);
    }
    friend ostream &operator<<(ostream &ot,const CComplex &comp)
    {
        return ot;
    }
    explicit operator double()
    {
        return 3.14;
    }
    operator tuple<double,double>()
    {
        return {real_part,img_part};
    }
};
