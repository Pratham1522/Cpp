#include<iostream>
using std::cout;
#define line(msg) cout<<"--------------"#msg"--------------------\n";

class CA
{
    bool isOnHeap;

    public:
    void Location()
    {
        if(true==isOnHeap)
        {
            cout<<"I am on Heap\n";
        }
        else if(false==isOnHeap)
        {
            cout<<"I am NOT ON Heap\n";
        }
    }
};
int main()
{   
    CA obj1;
    CA* obj2 = new CA();
    CA obj3;
    CA* obj4 = new CA();
    
    line(NotOnHeap);

    obj1.Location();
    obj3.Location();

    line(OnHeap);
    obj2->Location();
    obj4->Location();
    return 0;
}