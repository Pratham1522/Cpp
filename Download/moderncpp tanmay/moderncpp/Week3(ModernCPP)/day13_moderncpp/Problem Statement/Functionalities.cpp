#include "Functionalities.h"

void Factorial(DataContainer &data, ResultContainer &result)
{
    int k = 0;
    for (int val : data)
    {
        if (val == 0 || val == 1)
        {
            result[10 + k++] = 1;
        }
        else
        {
            int ans = 1;
            for (int count = 2; count <= val; count++)
            {
                ans *= count;
            }
            result[10 + k++] = ans;
        }
    }
}

void Sq(DataContainer &data, ResultContainer &result)
{
    if (data.empty())
    {
        throw std::runtime_error("Conatiner is Empty !!!");
    }
    int k = 0;
    for (auto val : data)
    {
        result[k++] = val * val;
    }
}

void Cube(DataContainer &data, ResultContainer &result)
{
    if (data.empty())
    {
        throw std::runtime_error("Conatiner is Empty !!!");
    }
    int k = 0;
    for (auto val : data)
    {
        result[5 + k++] = val * val * val;
    }
}

void MapThreadsToFunction(ThreadsArray &th, DataContainer &data, ResultContainer &result)
{
    th[0] = std::thread(&Sq, std::ref(data), std::ref(result));
    th[1] = std::thread(&Cube, std::ref(data), std::ref(result));
    th[2] = std::thread(&Factorial, std::ref(data), std::ref(result));

    /*
    Second Alternative-
    auto itr = th.begin();
    *itr++= std::thread(&Sq,std::ref(data),std::ref(result));
    *itr++= std::thread(&Cube,std::ref(data),std::ref(result));
    *itr++= std::thread(&Factorial,std::ref(data),std::ref(result));

    */
}

void JoinThreads(ThreadsArray &th)
{
    for (std::thread &t : th)
    {
        if (t.joinable())
        {
            t.join();
        }
    }
}

void Display(ResultContainer &result)
{
    for (int val : result)
    {
        std::cout << val << std::endl;
    }
}

void Input(DataContainer &data)
{

    int val{-1};
    int count = 5;
    while (count != 5)
    {
        std::cin >> val;
        if (val < 0 || val > 10)
        {
            continue;
        }
        data[count++] = val;
    }
}
