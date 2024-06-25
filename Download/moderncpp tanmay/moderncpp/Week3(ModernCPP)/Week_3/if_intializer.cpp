#include<iostream>
#include <array>

bool IsEven (int number)
{
    return number % 2 == 0;
}

std::array<int,5> MakeValues()
{
    return std::array<int,5>{1,2,3,4,5};
}

int main()
{
    std::cout<<"Hello"<<"\n";

    //  If we create something in if statement then if will remain till the ladder of if

    // Decclaration and then condition check
    // Only use one variable 

    if(bool ans = IsEven(13);ans)
    {
        std::cout<<"Number is Even"<<"\n";
    }
    else
    {
        std::cout<<"Number is Odd"<<"\n";
    }

    if(std::array<int,5> result = MakeValues() ; result[0] > -1)
    {
        std::cout<<result.front();
    }
    else 
    {
        std::cout<<"Negative No";
    }

    for (int i = 0;i<10;i++)
    {
        std::cout<<i*i<<"\n";
    }

    std::cout<<"Good Bye"<<"\n";
}