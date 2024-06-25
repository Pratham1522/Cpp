#include<thread>
#include<iostream>
#include<future>
#include<mutex>
#include<condition_variable>

std::mutex mt;
std::condition_variable cv;
bool flag {false};

void Producer(int& num){
    std::lock_guard<std::mutex> lock(mt);
    num=100;
    flag= true;
    cv.notify_one();
}
void Consumer(int &num){
    std::unique_lock<std::mutex> lock(mt);
    cv.wait(lock,[](){return flag;});
    std::cout<<"number is: "<<num*10<<"\n";
}

int main(){
    int num=4;
    std::thread t1(Producer,std::ref(num));
    std::thread t2(Consumer,std::ref(num));
    t1.join();
    t2.join();
}