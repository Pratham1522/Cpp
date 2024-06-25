#include "DataOperation.h"

#include <iostream>

int main()
{

    DataOperation *ptr = DataOperation::GetInstance(10); //

    std::thread t1(&DataOperation::Producer_Input, ptr);
    std::thread t2(&DataOperation::Consumer_Operation, ptr);
    if (t1.joinable())
    {
        t1.join();
    }
    if (t2.joinable())
    {
        t2.join();
    }

    return 0;
}