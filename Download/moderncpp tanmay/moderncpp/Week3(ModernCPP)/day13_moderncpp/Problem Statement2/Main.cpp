#include "Fun.cpp"
#include <iostream>

int main()
{

    std::thread t1(&Producer_Input);
    std::thread t2(&Consumer_Operation);

    t1.join();
    t2.join();
}
