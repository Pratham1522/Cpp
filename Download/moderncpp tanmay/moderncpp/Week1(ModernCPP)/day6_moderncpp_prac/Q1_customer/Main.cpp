#include<iostream>
#include "Functionalities.h"

int main(){
    Container data;
    createObjects(data);
    std::cout<<FindCustomerIDByMaxTransactionAmount(data);
    Container solution = FindContainerOfSameType(data,CustomerType::VIP);
    for(auto obj:solution){
        std::cout<<*obj;
    }
    Container ans = FindInstancesinSameRange(data);
    for(auto obj:ans){
        std::cout<<*obj<<"\n";
    }
    FindInstanceOfHighestnLowest(data);
    std::cout<<FindAverageOfSameType(data,CustomerType::VIP)<<"\n";
    std::cout<<FindIfAllTypeAreSame(data);

    Customer c1(1,"abc",CustomerType::PREMIUM,{1,2,3,4,5},600);
    Customer c2(2,"abcd",CustomerType::PREMIUM,{1,2,3,4,5},300);
    c1+c2;
}
