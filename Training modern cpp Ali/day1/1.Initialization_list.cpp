#include<iostream>
using std::cout;
#define line(msg) cout<<"*------------------- "#msg" ---------------------*\n";

class CA
{
    int x,y,z;
    public: 
    // intitalisation list : direct initilaisation , 
    //order of init list will map to order of var declaration.
    // body of constructor : assignment(many copies will be created)
    // body of constructor must be used for ##RAII##

    // CA(int par):x(par),y(par),z(par)   //10,10,10
    // CA(int par):x(par),y(x),z(y)       //10,10,10
    // CA(int par):y(par),x(y),z(x)          //g,10,g
    CA(int par):y(x),x(par),z(y)           //10,10,10
    {
       cout<<"x="<<x<<", y="<<y<<", z="<<z<<" \n"; 
    }
};
int main()
{
    line(welcome);
    CA obj(10);
    line(come_back_again);
    return 0;
}