#include<iostream>
#include<future>

// I guess 
// We use async when we want to return a value from thread
// return a value from child thread to main thread



int factorial(int N)
{
    int res = 1;
    for(int i = 1;i<N;i++)
    {
        res = res * i;
    }
    return res;
}

int main()
{
    int x;

    std::future<          int          > fu = std::async(factorial , 10);
    //---------<return type of function>

    x = fu.get();
    // this will fetch the value after completion of child thread
    std::cout<<x;
    return 0;

}