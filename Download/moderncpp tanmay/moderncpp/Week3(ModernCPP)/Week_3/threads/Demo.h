#ifndef DEMO_H
#define DEMO_H

#include <iostream>

class Demo 
{
private:
    int arr;
public:
    Demo() {
        arr = 10;
    } // Default constructor
    Demo(const Demo&) = default; // Copy constructor
    Demo& operator=(const Demo&) = delete; // Copy assignment operator
    Demo(Demo&&) = delete; // Move constructor
    Demo& operator=(Demo&&) = delete; // Move assignment operator
    ~Demo() = default; // Destructor

    void fn()
    {
        for (int i = 0;i<10;i++)
        {
            std::cout<<arr*i<<" ";
        }
    }

    static void Sfn()
    {
        std::cout<<"Static";
    }


};



#endif // DEMO_H
