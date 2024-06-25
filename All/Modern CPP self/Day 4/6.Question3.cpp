#include<iostream>
using std::cout;
#define line(msg)   cout<<"--------------(msg)--------------------\n";

class CA
{
public: 
    // virtual void fun()
    void fun()
    {
        cout<<"Apple \n";
    }
} ;
class CB : public CA
{
    public:
    void fun()
    {
        cout<<"Orange \n";
    }
};
int main()
{   
    int par = 10;
    try
    {
        CA obCb;
        if(10==par)
        {
            throw obCb;
        }
    }
    catch(CB& ob)
    {
        ob.fun();
    }
    catch(CA& ob)
    {
        ob.fun();
    }
    

    return 0;
}
// base class can catch derived object
//polymorphism works only on pointers and references.
//slicing
//derived first then base in catching