#include <iostream>

class A{
    public:
    virtual void print(int a=10){std::cout<<a;}
};
class B :public A{
    public: 
    void print(int a =20){std::cout<<a;}
};
int main(){
    // A* obj=new B(); //runtime
    // obj->print();
    A* a;
    B b;
    a=&b;
    a->print();
}