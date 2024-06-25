#include<iostream>

class A
{
    int x;
    public:
        A()
        {
            x=10;
        }
        void show()
        {
            std::cout<<" x= "<<x;
        }
};
class B:public A
{
    int y;
    public:
        B()
        {
            y=20;
        }
        void show()
        {
            std::cout<<" y= "<<y;
        }
};
class C:public A
{
    int z;
    public:
        C()
        {
            z=20;
        }
        void show()
        {
            std::cout<<" z= "<<z;
        }
};
class D:public B,public C
{

};

int main()
{
    D d1;
    d1.B::show();
}