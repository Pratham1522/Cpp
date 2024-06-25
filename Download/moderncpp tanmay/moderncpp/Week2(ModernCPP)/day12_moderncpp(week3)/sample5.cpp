
/*
6 func
1) takes 5 num as input from user saves it into an array
2) compute square of 1 input integer
3) computes cube of one input integer
4) computes 100 times the value of one input integer
5) computes factorial of one integer
6) computes Nth fibonacci series value where N is the integer as input

perform function f[i+2] on arr[i]
eg f2(data[0])...
input constraint : all input must be between 1 to 10;
1 2 3 4 5
op: 1 8 300 24 5 
  */
#include<iostream>
#include<thread>
#include<array>
#include<functional>

void Adaptor(std::array<int,5>arr,std::function<void(int)>fn){
    for(int i=0;i<5;i++){
        fn(arr[i]);
    }
}

int main(){
    int num;
    std::array<int,5>arr;
    std::cout<<"enter num: ";
        std::cin>>num;
        for(int i=0;i<num;i++){
            std::cin>>arr[i];
    }
    std::array<std::function<void(int)>,5>fn {  
    [](int num){
        std::cout<<num*num<<"\n";
    },
    [](int num){
        std::cout<<num*num*num<<"\n";
    },
    [](int num){
        std::cout<<100*num<<"\n";
    },
    [](int num){
        int ans=1;
        for(int i=num;i>=1;i--){
            ans*=i;
        }
        std::cout<<ans<<"\n";
    },
    [](int num){
        int a=1,b=1;
        int number;
        for(int i=2;i<num;i++){
            number=a+b;
            a=b;
            b=number;
        }
        std::cout<<number<<"\n";
        }
    };
    std::thread t1(&Adaptor,arr,fn[0]);
    std::thread t2(&Adaptor,arr,fn[1]);
    std::thread t3(&Adaptor,arr,fn[2]);
    std::thread t4(&Adaptor,arr,fn[3]);
    std::thread t5(&Adaptor,arr,fn[4]);

    if(t1.joinable()){
        t1.join();
    }
    if(t2.joinable()){
        t2.join();
    }
    if(t3.joinable()){
        t3.join();
    }
    if(t4.joinable()){
        t4.join();
    }
    if(t5.joinable()){
        t5.join();
    }
}

