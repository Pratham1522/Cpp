#include<iostream>
using std::cout;
#define line(msg) cout<<"*------------------- "#msg" ---------------------*\n";

class CA
{ 
    int* a;
    public:
    CA(int val):a(new int(val))
    {
        cout << "CA Ctor a : [ " << a << " ]\n";
    }
    CA(const CA& obj):a(new int(*obj.a))
    {
        cout << "CA Deep Copy a : [ " << a << " ]\n";
    }
    CA& operator=(const CA& obj)
    {
        cout << "CA Deep Assignment a : [ " << a << " ]\n";
        *a=*obj.a;
        return *this;
    }
    ~CA()
    {
        delete a;
    }

};

int main()
{
    line(welcome);

    CA obj1(100);
    CA obj2=obj1;
    obj1=obj2;
    line(end);
    return 0;
}  