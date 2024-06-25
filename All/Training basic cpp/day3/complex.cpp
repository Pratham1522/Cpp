#include<iostream>
using namespace std;

// sum of two coples number as c=c1+c2 not as c1.add(c2)
// operator . :: ? : cant be overloaded
// precedence of operator cant ve changed through overloading
// overloading allowed for user defined type.
class complex{
    double r;
    double i;

    public:
    complex(double rr=0,double ii=0){
        r=rr;
        i=ii;
    }
    complex operator + (complex c2){
        complex t;
        t.r = r+c2.r;
        t.i=i+c2.i;

        return t;
    }
    complex operator - (complex c2){
        complex t;
        t.r=r-c2.r;
        t.i=i-c2.i;
        return t;
    }
    void print(){
        cout<<this->r<<"i+"<<this->i<<"j \n";
    }
};
int main(){
    complex a(1.0,1.0);
    complex b(2.0,2.0);
    complex d(3.0,3.0);
    complex c;
    c=a-d;
    cout<<"c=";
    c.print();
}
