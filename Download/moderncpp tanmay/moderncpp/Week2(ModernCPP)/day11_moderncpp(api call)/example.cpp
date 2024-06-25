//take 5 values from the user as input
//take a container of 5 functions
//each function takes 1 integer as input returns void
//create an adaptor that accepts array of 5 values and array of 5 functions
//map function at i position to data at i position

//[10   20  30]
//[f1   f2  f3]
#include<iostream>
#include<array>
#include<functional>


void Adaptor(std::array<int,5>arr, std::array<std::function<void(int)>,5> fn){
    for(int i=0;i<5;i++){
        fn[i](arr[i]);
    }
}

int main(){
    std::array<int,5> arr;
    std::cout<<"enter 5 values: ";
    for(int i=0;i<5;i++){
        std::cin>>arr[i];
    }
        std::array<  std::function<void(int)>,5  > fn{
        [](int n1){std::cout<<"Funcctiion1 called\n";},
        [](int n1){std::cout<<"Funcctiion2 called\n";},
        [](int n1){std::cout<<"Funcctiion3 called\n";},
        [](int n1){std::cout<<"Funcctiion4 called\n";},
        [](int n1){std::cout<<"Funcctiion5 called\n";}
    };
    Adaptor(arr,fn);

}
