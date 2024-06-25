
## singleton class
- make constructor and destructor private
- use static pointer to hold object
- make object creator and release methods in private only
- declare a friend class handler  

**Handler class**
- make a handler class to handle base class and inherit from base class
- use a static count to keep track of obj number
- create a base* pointer to manage obj of base class
- overload -> and * operator to access base obj using handler class
- delete new and delete operator.
```cpp
#include<iostream>
using std::cout;

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
        delete head; // it delete's the value store at head.
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
    Handler h1;
    Handler h2;
    h2->x=4;        //h2.operator->(pt)->x;
    cout<<"h1 and h2 points to same obj so h1->x="<<h1->x<<"\n";
    (*h1).x=80;     //h2.operator*(pt)->x;
    
    return 0;
}
```
