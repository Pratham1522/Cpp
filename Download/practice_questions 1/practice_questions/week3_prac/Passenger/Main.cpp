#include "DataOperations.h"

int main(){
    std::shared_ptr<DataOperations> ptr = DataOperations::getInstance();
    ptr->CreateObjects();
    std::promise<std::string> pr;
    std::future<std::string> fu=pr.get_future();
    std::future<Container> answer = std::async(std::launch::async,&DataOperations::NameDoesNotMatchContainer,ptr,std::ref(fu));
    std::thread t1(&DataOperations::DisplayPassengerInstanceOfSameID,ptr,1);
    t1.join();
    std::cout<<"enter the name you want to search for: ";
    std::string s;
    std::cin>>s;
    pr.set_value(s);
    answer.wait();
    Container result = answer.get();
    for(auto obj:result){
        std::cout<<*obj<<"\n";
    }

    std::future<void> print = std::async(std::launch::async, &DataOperations::Print,ptr);
    std::future<void> input = std::async(std::launch::async,&DataOperations::Input,ptr);
    std::future<void> factorial = std::async(std::launch::async,&DataOperations::FacOfInput,ptr);
}

