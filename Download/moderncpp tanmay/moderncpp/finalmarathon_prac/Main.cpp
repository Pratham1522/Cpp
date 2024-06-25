// #include "Functionalities.h"

// int main(){
//     DataContainer data;
//     CreateObjects(data);
//     DataContainer result;
//     if(FindMatchingInstaces(data,2).has_value()){
//         result=FindMatchingInstaces(data,2).value();
//     }
//     for(auto obj:result){
//         std::cout<<*obj<<"\n";
//     }
// }

#include "MapFunctionalities.h"

int main(){
    DataContainer data;
    CreateObjects(data);
    std::cout<<MaxPerBookingCharges(data)<<"\n";
    std::cout<<MaxSeatCount(data,3)<<"\n";
    std::cout<<"average booking per charges: "<<AveragePerBookingCharges(data);
    std::cout<<"count of cab is: "<<CountOfInstanceWithTypeCab(data);
    std::list<TouristVehiclePtr> answer = ReturnNInstances(data,1);
    for(auto i:answer){
        std::cout<<*i<<"\n";
    }
}

/* 
    HASHTABLE ENTRIES ARE STD::PAIR<K,V>;
    i.e. std::pair cannot use COPY SEMANTICS

    copy, copy_n, copy_if cannot be done in it!!
*/