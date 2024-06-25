#include <iostream>

// function overloading-polymorphism
/*
two or more funs with same name but different argument list
is called as function overloading
** Note: return type is not considered.
*/
class Demo
{
public:
   
    // int add(int a, int b)
    // {
    //     std::cout << "\n int+int = " << a + b;
    //     return a+b;
    // }
    void add(int a, int b)
    {
        std::cout << "\n int+int = " << a + b;
    }
    // void add(float a, float b)
    // {
    //     std::cout << "\n float+float =" << a + b;
    // }
     void add(double a, double b)
    {
        std::cout << "\n double+double =" << a + b;
    }
};

int main()
{
    Demo d;
     d.add(1.6f,3.7f);
    return 0;
}