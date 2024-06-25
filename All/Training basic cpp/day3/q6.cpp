#include<iostream>
using namespace std;

class A{
    mutable int a;

    public:
    A(){
        cout<<"A Constructor called \n";
    }
    ~A(){
        cout<<"A Destructor called \n";
    }
};

class B{
    A a;

    public:
    B(){
        cout<<"B Constructor called \n";
    }
    ~B(){
        cout<<"B Destructor called \n";
    }
};

int main(){
    // B b1;
}