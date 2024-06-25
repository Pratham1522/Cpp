#include<iostream>
#include<optional>
#include<list>

using Container = std::list<int>;

// A function to retun a list of even numbers in a given list
std::optional<Container> ReturnEvenList(Container &data)
{
    Container result ;
    for (int i : data)
    {
        if(i%2 == 0 )
        {
            result.push_back(i);
        }
    }
    if(result.empty())
    {
        return std::nullopt;
    }
    return result;
}




int main()
{
    Container data {1,3,5,7,9};
    std::optional<Container> Result = ReturnEvenList(data);
    Container Final_result;

    if (Result.has_value())
    {
        Final_result = Result.value();

        for(int i : Final_result)
        {
            std::cout<<i<<" ";
        }
    }
    else{
        std::cout<<"No nuber Divided by Two";
    }



    return 0;
}