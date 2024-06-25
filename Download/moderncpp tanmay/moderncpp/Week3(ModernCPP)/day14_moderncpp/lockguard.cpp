#include<iostream>
#include<mutex>
#include<thread>

std::mutex mt;
int count=0;

void F1(){
        std::lock_guard<std::mutex>lk(mt);
    for(int i=0;i<10000;i++){
        count++;
    }
}

int main(){
    std::thread t1(F1);
    std::thread t2(F1);
    if(t1.joinable()){t1.join();}
    if(t2.joinable()){t2.join();}
    std::cout<<count<<"\n";
}
