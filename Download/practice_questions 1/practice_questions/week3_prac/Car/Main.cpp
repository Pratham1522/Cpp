#include "Operations.h"
#include<thread>
#include<future>

int main(){
    std::shared_ptr<Operations> ptr = Operations::getInstance();
    ptr->CreateObject();
    std::future<std::optional<Container>> result = std::async(std::launch::async,&Operations::ReturnThoseCarsThatHavePriceMoreThanThreshold,ptr,1000);
    std::optional<Container> answer = result.get();
    if(answer.has_value()){
        for(auto obj:answer.value()){
            std::cout<<*obj<<"\n";
        }
    }
    else{
        std::cout<<"DATA IS EMPTY\n";
    }
}