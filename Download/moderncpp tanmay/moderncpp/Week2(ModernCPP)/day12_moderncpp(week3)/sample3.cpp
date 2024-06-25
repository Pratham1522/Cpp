/* 
original mt: 1000
    if I do  100 transactions each to withdraw 10 rupees and 100 more transactions each to deposit 10 rupees
final amount : 1000
*/

#include<iostream>
#include<thread>
#include<mutex>

std::mutex mt;

int amount = 1000;

void Withdraw(){
    for(int i=0;i<100;i++){
        std::this_thread::sleep_for(std::chrono::milliseconds(2));
        std::lock_guard<std::mutex>lk(mt);
        amount-=10;
    }
}

void Deposit(){
    for(int i=0;i<100;i++){
        std::this_thread::sleep_for(std::chrono::milliseconds(2));
        std::lock_guard<std::mutex>lk(mt);
        amount+=10;   
    }
}

int main(){
    std::thread t1(&Withdraw);
    std::thread t2(&Deposit);
    if(t1.joinable()){
        t1.join();
    }
    if(t2.joinable()){
        t2.join();
    }
    std::cout<<amount<<"\n";
}