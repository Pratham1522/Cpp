#include<iostream>
using std::cout;
#define line(msg)   cout<<"--------------(#msg)--------------------\n";

class CA
{
    int* a;
    public:
    CA():a(new int (1000))
    {
        cout<<"C-tor\n";
    }
    CA(const CA& par): a(new int(*par.a))
    {
        cout<<"Deep Copy\n";
    }
    CA(CA&& par) noexcept :a(par.a){   //move ctor
        // this == rvalue obect address
        //par==temp
        // par.a=NULL;
        cout<<"Move C-tor\n";
    }
    ~CA()
    {
        cout<<"D-tor\n";
        delete a;
    }
};
CA Factory()
{
    CA temp;
    cout<<"Do Bussiness \n";
    return temp;
}
int main()
{
    CA obj=Factory();
    line();
    // CA obj1(obj);
    line();
    return 0;
}
//r value : middle man that stores the object