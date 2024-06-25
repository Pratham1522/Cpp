#include<iostream>
#include<thread>
#include<condition_variable>


int value{-1};
std::condition_variable cv;
std::mutex mt;
bool flag{false};

void Producer(){
    std::cin>>value;
    //
    flag=true;
    cv.notify_one();
}

void Consumer(){
    int result;
    std::unique_lock<std::mutex>ul(mt);
    cv.wait(ul,[](){return flag;});
    result =value*value;
    std::cout<<"square is: "<<result;
}

int main(){
    std::thread t1(Producer);
    std::thread t2(Consumer);
    if(t1.joinable()){t1.join();}
    if(t2.joinable()){t2.join();}
}
