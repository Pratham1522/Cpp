#include<iostream>
using std::cout;
using std::endl;
#define line(msg) cout<<"---------------"#msg"------------------\n";

class A
{
    static void* operator new(size_t size){
        return size;
    }
    static void operator delete(void *pv)
    {
        free(pv);
    }
}