#include"Demo.h"
#include<thread>
#include<iostream>
#include<functional>
#include<mutex>

std::mutex mt;

std::string shared_string = "";

void Function(int arr)
{
    for (int i = 0;i<10;i++)
    {
        std::cout<<arr*i<<" ";
    }
}

void F1()
{
    std::lock_guard<std::mutex> lock(mt);
    shared_string = "a";
}

void F2()
{
    std::lock_guard<std::mutex> lock(mt);
    shared_string = "abba";
}



void Adaptor(int n , std::function<void(int)> fn ){
    fn(n);
}

int main()
{
    // Function
    std::thread t1(&Function ,10);
    if(t1.joinable())
    {
        t1.join();
    }

    // Lambda function
    std::thread t2([](int n){std::cout<<n*20;},20);
    if(t2.joinable())
    {
        t2.join();
    }

    // Adapator
    std::thread t3(&Adaptor , 10 , [](int n){std::cout<<n*20;});
     if(t3.joinable())
    {
        t3.join();
    }

    // Non static Member Function
    Demo d;
    std::thread t4(&Demo::fn , &d);
    if(t4.joinable())
    {
        t4.join();
    }

    std::thread t5(&Demo::Sfn);
    if(t5.joinable())
    {
        t5.join();
    }

    // Use Lockguard when accessing shared memory (even cout buffer)

    std::thread ts(&F1);
    std::thread ts1(&F2);

    ts.join();
    ts1.join();


    
    return 0;
}