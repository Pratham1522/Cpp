#include <iostream>

// function overloading-polymorphism
class Demo
{

public:
    void add(int p, float q)
    {
        std::cout << "\n int+float = " << p + q;
    }
    void add(float p, int q)
    {
        std::cout << "\n float+int = " << p + q;
    }
    void add(int a, int b, int c)
    {
    }

    void add(int a, int b)
    {
        std::cout << "\n int+int = " << a + b;
    }
    void add(float a, float b)
    {
        std::cout << "\n float+float =" << a + b;
    }
};

int main()
{
    Demo d;
    d.add(10, 20);
    d.add(10.5f, 40.5f);
    return 0;
}