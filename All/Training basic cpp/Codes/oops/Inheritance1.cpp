#include<iostream>

class A
{
    private :  int p;
    public:    int q;
    protected: int r;
};
class B:private A
{
  
    // int q - private 
    //int r-private
  public:  void show()
        {
            q=1000;
            r=4000;
        }  
};
class C:public B{


    public:
        void show()
        {
             //q=5;//private
             //r=5;
        }
};
int main()
{ 
    A a1;
    a1.q=10;
    //a1.r=800;//protected-error

    B b1;
    //b1.q=10;
    //b1.r=4;//private - error
}