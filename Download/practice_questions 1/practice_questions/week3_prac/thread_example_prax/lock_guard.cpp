#include<thread>
#include<iostream>
#include<mutex>

std::mutex m1;

int buffer=0;

void solve(const char* ptr, int loop){
    for(int i=0;i<loop;i++){
    std::lock_guard<std::mutex> lock(m1);
    // std::unique_lock<std::mutex> lock();
        ++buffer;
        std::cout<<ptr<<buffer<<"\n";
    }
}

int main(){
    std::thread t1(solve,"T0",5);
    std::thread t2(solve,"T1",5);
    t1.join();
    t2.join();
}