#include<iostream>
using std::cout;
#define line(msg) cout<<"*------------------- "#msg" ---------------------*\n";

class CA
{ 
    int* a;

    public:
    CA(int val):a(new int(val))
    {
        cout << this << " : CA Ctor a : [ " << a << " ]\n";
    }
    CA(const CA& par): a(par.a)
    {
        CA& caRef =const_cast<CA&>(par);
        caRef.a = NULL;
        cout << this << " : CA Shallow Copy a : [ " << a << " ]\n";
    }
    CA& operator=(const CA& par)
    {
        if(this == &par)
        {
            return *this;
        }
        cout << this << " : CA Shallow Assignment a : [ " << a << " ]\n";
        CA temp(par);
        this->Swap(temp);
        return *this;
    }
    void Swap(CA &temp)
    {
        std::swap(this->a,temp.a);
    }
    ~CA(){
        cout << this << " : CA D-tor a : [ " << a << " ]\n";
        delete a;
    }
};

int main()
{
    line(welcome);

    CA obj1(100);
    CA obj2(200);// obj1;

    line();
    line();
    obj1 = obj2;
    line();

    line(end);
    return 0;
}  