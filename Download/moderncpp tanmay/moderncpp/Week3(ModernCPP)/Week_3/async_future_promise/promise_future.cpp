#include<iostream>
#include<future>

// I guess 
// pass a value from parent thread to child thread

// tell child thread that i dont have that value but i will send you that value in future


int factorial(std::future<int>& f)
{
    int N = f.get();
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

    std::promise<            int        > p;
    //---------<What we pass in function>
    std::future<            int         > f = p.get_future();

    std::future<          int          > fu = std::async(factorial , std::ref(f));
    //---------<return type of function>----------------------------"IMP"--------send value by reference


    // kepp the promis and give the value
    p.set_value(5);


    x = fu.get();
    // this will fetch the value after completion of child thread
    std::cout<<x;
    return 0;

}

// I Async set the try catch block to .get functions