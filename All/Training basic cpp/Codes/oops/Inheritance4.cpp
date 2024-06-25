#include<iostream>
class A
{   int x;
    public:
        A() {   x=10;  }
        void baseshow()
        {
            std::cout<<" x= "<<x;
        }
};
class B:public A
{   int y;
    public:
        B() {   y=20;     }
        void deriveshow()
        {
            std::cout<<" y= "<<y;
        }
};
int main()
{
    A *ptr= new B;
  //  ptr->
}