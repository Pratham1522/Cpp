#include<iostream>

int Multiply(int a, int b)
{
    return a * b;
}

void MultiplyAndLog(int a, int b)
{
    int result = Multiply(a, b);
    std::cout << result << std::endl;
}

int main()
{
    MultiplyAndLog(5, 10); // Output: 50
    MultiplyAndLog(4, 5);   // output: 20
}