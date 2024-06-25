#include<iostream>
using namespace std;

class complex
{
    int re;
    int im;

    public :
    complex(int r=0,int i=0);
    void display();
    complex& operator+ (const complex& c2);
    friend ostream& operator << (ostream &o,const complex &c);
};
complex::complex(int r,int i){
    re=r;
    im=i;
}
void complex::display() {
    cout<<"Complex Number is "<<re<<"+"<<im<<"i \n";
}
complex& complex::operator+ (const complex &c2){
    re += c2.re ;
    im += c2.im ;
    return *this;
}
ostream& operator << (ostream &o,const complex &c){
    o<<c.re<<"+ "<<c.im<<"i \n";
    return o;
}



int main()
{
    complex c1(3,4);
    complex c2(5,6);
    complex c3(2,3);
    complex c4=c1+c2+c3;
    c4.display();
    cout<<c4;
}