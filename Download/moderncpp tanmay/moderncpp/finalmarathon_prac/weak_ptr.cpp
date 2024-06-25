#include<memory>
#include<iostream>
#include<thread>

void Magic(std::shared_ptr<int>& p2){
    std::this_thread::sleep_for(std::chrono::seconds(5));
    std::cout<<*p2<<"\n";
}

int main(){
    std::shared_ptr<int> p;
    if(p.reset(new int);p){
        Magic(p);
    }
    std::weak_ptr<int> wk(p); //wk is stalking or oserving or tracking p
    if(wk.lock()){
        std::cout<<"resource still present\n";
        std::cout<<*p;
        std::shared_ptr new_owner = wk.lock();
    }
    else{
        std::cout<<"owner no longer  valid\n";
    }
}
//this line is tension wala line
