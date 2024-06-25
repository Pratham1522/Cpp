#include<iostream>
using std::cout;
#define line(msg) cout<<"-------------------"#msg"---------------------\n";

// make constructor n destructor private
// use a static pointer to manage object
// make obj creator and delete function as static n private.
// create a new class to handle the object
//overload -> and * operator to access CA obj using Handler class.
class CA
{
    CA()
    {
        cout<<"Default C-tor \n";
    }
    ~CA()
    {
        cout<<"CA D-tor \n";
    }

    static CA* head; // static member variable 

    static CA* makeObj()
    {
        if(head == NULL)
        {
            head=new CA();
        }
        return head;
    }
    static void releaseObj()
    {
        delete head;
        head=NULL;
    }
    friend class Handler;

    public:
    int x=7;
    void fun()
    {
        cout<<"CA fun \n";
    }
};
CA* CA::head = NULL;

class Handler
{
    static int count;
    CA* pt;

    public:
    explicit Handler():pt(CA::makeObj())
    {   
        count++;
        cout<<"count : "<<count<<"\n";
    }
    CA* operator->()
    {
        return pt;
    }
    CA& operator*()
    {
        return *pt;
    }
    //make new and delete inaccessible to use.
    static void* operator new(size_t) = delete;
    static void* operator new[](size_t) = delete;
    static void operator delete(void*) = delete;
    static void operator delete[](void*) = delete;

    ~Handler() {
        count--;
        if (count == 0)
        {
            CA::releaseObj();
        }
    }
};
int Handler::count = 0;

int main()
{
    line(welcome);

    Handler h1;
    Handler h2;
    h2->x=4;        //h2.operator->(pt)->x;
    cout<<"h1 and h2 points to same obj so h1->x="<<h1->x<<"\n";
    (*h1).x=80;     //h2.operator*(pt)->x;
    
    line(come_back_again);
    return 0;
}