#include<vector>
#include<iostream>

template <typename T>
T add(T n1)
{
    return n1;
}
/*



*/

template<typename T , typename... Remaining> // Args could be 0 or more(...)
T add(T n1 , Remaining... args)
{
    return n1 + add(args...);
}

// Find minimum between values
// - count of values
// - type of values



int main()
{
    
    std::cout<<add<int>(10,20,30,40);
    return 0;
}
/*
 How to create a type agnostic logic that can apply an operator on 0 or more argumnets by using recursion as its problem solving techniques.
 example : add 1 or more numbers
 example : use * operator on 1 or more values
*/