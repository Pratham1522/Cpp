#include<iostream>
using std::cout;
using std::endl;  //"\n"+flush buffer

class A{
    //state 
    int x;
    mutable int y;
    const int z;  //initialise in initialiser list, or constructor

    // non state
    static int s;
    static const int sc;
    int &a;   //ref varivble : dont belong to object

    public:
    A(int par):x(par),y(par),z(par),a(par){

    }
    void f1() const{
        y++;
        s++;
        a++;
    } //inspector constant function: check the state of const must not be changed
    void f2(){}   //mutator  : change the state of object.
    ~A(){}
};
static int j;//normal static member : can be accessed only within file.
int k;//use extern with global var to use in another file.
//copy constructor :const is mandatory

class cat{
    public:
    cat(){}
    cat(const cat&){}
    cat& operator=(const cat&){} //copy assignment operator overloading
};


//delete opertor vs operator delete
