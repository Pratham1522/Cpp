#include<iostream>
using std::cout;
#define line cout<<"___________________________\n"

void fun(int par)
{
    cout << "Apple\n";
    if (10 == par)
    {
        throw 100;
    }
    cout << "Orange\n";
}

class CA
{
public:
    CA()
    {
        cout << "CA ctor\n";
    }
    CA(const CA&)
    {
        cout<<"CA Copy C-tor \n";
    }
    CA& operator=(const CA&)             
    {
        cout<<"CA Assign operator \n";
        return *this;
    }
    ~CA()
    {
        cout << "CA D-tor\n";
    }
};

int main()
{
    int par = 10;
    cout << "start\n";
    try
    {
        CA obj;
        cout << "Apple\n";
        if (10 == par)
        {
            throw obj; //copy constructor 2 times.
        }
        cout << "Orange\n";
    }
    catch (CA exp)
    {
        cout << "CA Exp : " << '\n';
    }
    cout << "Done\n";
    return 0;
}