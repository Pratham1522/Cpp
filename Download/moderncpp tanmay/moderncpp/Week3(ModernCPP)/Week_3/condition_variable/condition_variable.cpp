#include<iostream>
#include<mutex>
#include<thread>
#include<condition_variable>

std::mutex mt;
int balance = 0;
std::condition_variable cv;


void WithdrawMoney(int money)
{
    std::cout<<"Checking Balance"<<"\n";

    std::unique_lock<std::mutex> ul(mt);
    cv.wait(ul , [&]{return balance > 0;}); // paramaeters are a lock and a predicate function
    // Checks for above condition if true the proceeds else releases the lock
    if (balance >= money)
    {
        balance = balance - money;
        std::cout<<"Amount Deducted \n";
    }
    else 
    {
        std::cout<<"Not Enough Money \n";
    }
}

void AddMoney(int money)
{
    std::lock_guard<std::mutex> lock(mt);
    balance += money ; 
    std::cout<<"Balance Added Successfully"<<"\n";
    
    cv.notify_one();
}


int main()
{
    std::thread t1(&WithdrawMoney , 500);
    std::thread t2(&AddMoney , 1000);

    if (t1.joinable())
    {
        t1.join();
    }
    if (t2.joinable())
    {
        t2.join();
    }
    return 0;
}