#include<iostream>
using std::cout;
#define line(msg)   cout<<"--------------(msg)--------------------\n";

class CA
{
    public:
    void fun(){
        cout<<"Apple \n";
    }
};
class Smart_ptr
{
    CA* pt;

    public:
    Smart_ptr(CA* pt=NULL):pt(pt)
    {
    }
    void fun()
    {
        cout<<"Oranges \n";
    }
    CA* operator ->()
    {
        return pt;
    }
};
int main()
{
    Smart_ptr* sm=new Smart_ptr(new CA);
    line();
    sm->fun();
    line();
    (*sm)->fun();
    line();
    return 0;
}
//overloaded operator works on obj ,not pointers