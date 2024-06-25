#include<vector>
#include<iostream>

// Improved version of vairadicTemplate 

template<typename... T>
auto add( T... n1)
{
    return (n1 + ...); // operation is right associative (rightmost bracket pehle)
}

int main()
{
    
    std::cout<<add<int>(10,20,30,40);
    return 0;
}
