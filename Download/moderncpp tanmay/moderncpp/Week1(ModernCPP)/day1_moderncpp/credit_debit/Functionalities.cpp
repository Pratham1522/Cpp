#include "Functionalities.h"
#include "SavingsAccount.h"
#include "VectorEmptyException.h"
#include<iostream>

void createObject(std::vector<BankAccount*>& data){
    data.push_back(new SavingsAccount("tanmay", 100000, 3000));
    data.push_back(new SavingsAccount("alice", 400000, 4000));
    data.push_back(new SavingsAccount("john", 300000, 5000));
}

float calculateAverage(std::vector<BankAccount*>& data){
    float total=0.0f;
    for(auto it : data){
        total+= it->accountBalance();
    }
    return total/data.size();
}

void Print(const Container &data)
{
    if(data.empty()){
        throw VectorEmptyException("Container is empty\n");
    }
    for(auto obj:data){
        std::cout<<*obj<<"\n";
    }
}
