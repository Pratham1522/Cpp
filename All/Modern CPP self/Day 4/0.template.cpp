#include<iostream>
using std::cout;
#define line(msg)   cout<<"--------------(msg)--------------------\n";

int main()
{

    return 0;
}



//constructor : resource aquisition,base class obj creation, vptr making
//destructor : 


//const is mandatory in copy constructor.
//CA(const CA&) = delete; //tell compiler dont provide default copy constructor.
//it means we can only pass as reference, and data in each obj is unique.

//prohibit heap obj : new + delete operator overloading, they are static by default.