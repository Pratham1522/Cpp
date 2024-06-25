#include<thread>
#include<future>
#include<iostream>
#include<mutex>
#include<condition_variable>

std::mutex mt;
std::condition_variable cv;
bool flag=false;

int TakeInput(int num){
    std::cout<<"enter number: ";
    std::cin>>num;
    flag=true;
    cv.notify_one();
    return num;
}

void Fact(std::future<int>& num){
    int n = num.get();
    std::unique_lock<std::mutex> ul(mt);
    cv.wait(ul,[](){return flag;});
    int answer=1;
    while(n>=1){
        answer*=n;
        n--;
    }
    std::cout<<answer<<"\n";
}

int main(){
    std::promise<int> pr;
    std::future<int> ft = pr.get_future();
    int num;
    std::future<int> inp = std::async(&TakeInput,std::ref(num));
    std::future<void> fact = std::async(&Fact,std::ref(ft));
    num=inp.get();
    pr.set_value(num);
    fact.wait();
    fact.get();

}
