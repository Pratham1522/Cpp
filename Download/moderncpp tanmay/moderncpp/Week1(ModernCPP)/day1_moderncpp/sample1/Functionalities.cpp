#include<iostream>
#include "Functionalities.h"
#include "SavingsAccount.h"

void CreateObjects(Container &data)
{
    data.push_back(
        new SavingsAccount(
            "Tanmay",
            10000.0f,
            new DebitCard(123,1234123412,"09/30",DebitCardType::VISA),
            5000.0f
        )
    );
    std::cout<<*data[0]<<'\n';
    data.push_back(
        new SavingsAccount(
            "ABCD",
            20000.0f,
            new DebitCard(124,12341234454,"10/30",DebitCardType::VISA),
            5000.0f
        )
    );

}

float AverageAccountBalance(Container &data)
{
    float total = 0.0f;
    for(Container::iterator itr=data.begin();itr!=data.end();++itr){
        total += (*itr)->accountBalance();
    }

    /* 
    for(BankAccount ptr : data){
        total += ptr->accountBalance(); 
    }
     */
    return total/data.size();
}

void deleteobjects(Container &data)
{
    for(auto obj:data){
        delete obj->accountDebitCard();
        delete obj;
    }
}
