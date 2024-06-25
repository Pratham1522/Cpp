#include<iostream>
using std::cout;
#define line(msg) cout<<"*------------------- "#msg" ---------------------*\n";

class singleton
{ 
    private:
    singleton()
    {
        cout<<"Default C-tor \n";
    }
    ~singleton()
    {
        cout<<"singleton D-tor\n";
    }
    static singleton* ptr;

    static singleton* createobj()
    {
        if(ptr==nullptr)
        {
            ptr = new singleton();
        }
        return ptr;
    }
    static void releaseobj()
    {
        delete ptr;
        ptr=nullptr;
    }
    friend class Handler;

    public:
    int x=0;
    void fun(){};

};
singleton *singleton :: ptr = nullptr;

class Handler
{
    static int count;
    singleton* obj;

    public:
    explicit Handler():obj(singleton::createobj())
    {
        count++;
        cout<<"count : "<<count<<"\n";
    }
    singleton* operator -> ()
    {
        return obj;
    }
    singleton& operator* ()
    {
        return  *obj;
    }
    static void* operator new(size_t ) = delete;
    static void* operator new[](size_t ) = delete;
    static void operator delete(void*) = delete;
    static void operator delete[](void*) = delete;

    ~Handler()
    {
        count--;
        if(count == 0)
        {
            singleton::releaseobj();
        }
    }
};
int Handler::count = 0;

int main()
{
    line(welcome);

    Handler h1;
    Handler h2;

    (*h1).x=78;


    line(end);
    return 0;
}  