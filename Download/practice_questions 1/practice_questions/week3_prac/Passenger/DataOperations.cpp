#include "DataOperations.h"

std::shared_ptr<DataOperations> DataOperations::ptr = nullptr;

std::shared_ptr<DataOperations> DataOperations::getInstance(){
    if(!ptr){
        ptr = std::make_shared<DataOperations>();
    }
    return ptr;
}

void DataOperations::CreateObjects()
{
    tickets.emplace_back(Ticket(100.0));
    tickets.emplace_back(Ticket(10.0));
    tickets.emplace_back(Ticket(20.0));
    m_data.emplace_back(
        std::make_shared<Passenger>(1,"tanmay",22,tickets[0],1234.0)
    );
    m_data.emplace_back(
        std::make_shared<Passenger>("2","john",10,tickets[1],134.0)
    );
    m_data.emplace_back(
        std::make_shared<Passenger>(3,"alice",16,tickets[2],222.0)
    );
}

void DataOperations::DisplayPassengerInstanceOfSameID(VType id)
{
    for(std::shared_ptr<Passenger>& obj:m_data){
        if(obj.get()->id()==id){
            std::cout<<*obj<<"\n";
        }
    }
}

Container DataOperations::NameDoesNotMatchContainer(std::future<std::string> &name)
{
    Container result;
    std::string givenname = name.get();
    for(std::shared_ptr<Passenger>& obj:m_data){
        if(obj && obj.get()->name() != givenname){
            result.push_back(obj);
        }
    }
    return result;
}

void DataOperations::Print()
{
    for(auto obj:m_data){
        std::cout<<*obj<<"\n";
    }
}

void DataOperations::Input()
{
    std::lock_guard<std::mutex>lock(mt);
    std::cout<<"enter number: ";
    std::cin>>n;
    flag=true;
    cv.notify_one();
}

void DataOperations::FacOfInput()
{
    std::unique_lock<std::mutex>ul(mt);
    cv.wait(ul,[&](){return flag;});
    int ans=1;
    for(int i=1;i<=n;i++){
        ans *= i;
    }
    std::cout<<"factorial is: "<<ans;
}
