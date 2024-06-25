#include<iostream>
using std::cout;
#define line(msg) cout<<"-------------------"#msg"---------------------\n";

class CA
{
    public:
    CA()
    {
        cout<<"Default C-tor \n";
    }
    // CA(const CA&)
    // {
    //     cout<<"CA Copy C-tor \n";
    // }
    // CA& operator=(const CA&)             
    // {
    //     cout<<"CA Assign operator \n";
    //     return *this;
    // }
    static void* operator new(size_t size)
    {
        cout<<"CA operator NEW \n";
        return malloc(size);
    }
    static void operator delete(void* pv)
    {
        cout<<"CA operator DELETE \n";
        free(pv);
    }
    ~CA()
    {
        cout<<"CA D-tor \n";
        // delete this;   //infinite loop
    }
};
int main()
{
    line(welcome);
    CA* obj1 = new CA();
    delete obj1;
    line(come_back_again);
    return 0;
}