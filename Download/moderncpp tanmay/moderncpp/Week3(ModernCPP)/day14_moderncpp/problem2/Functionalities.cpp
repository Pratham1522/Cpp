#include "Functionalities.h"

void AllocateMemory(int &num)
{
    int *num = new int;
}

void ComputeSquare(int &number)
{
    number = number*number;
}

void Print(int &number)
{
    std::cout<<"the square of number is: ";
    ComputeSquare(number);
}

void Input(int &number)
{
    std::cout<<"enter 1 integer: ";
    int n;
    std::cin>>n;
    number = n;
}
