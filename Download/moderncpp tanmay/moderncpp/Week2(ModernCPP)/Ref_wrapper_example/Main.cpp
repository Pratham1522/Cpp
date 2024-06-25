#include "Functionalities.h"

int main(){
    InvoiceContainer inv;
    Container data;
    CreateObjects(data,inv);
    std::cout<<"highest bill amount is: "<<HighestBillAmount(data)<<"\n";
    Container result = FindNInstance(data,2);
    //Container solution = BindNInstace(data,999);
    for(std::shared_ptr<Bill> &obj:result){
        std::cout<<*(obj)<<"\n";
    }
    // std::cout<<"*****************\n";
    // for(auto obj:solution){
    //     std::cout<<*obj<<"\n";
    // }
}

// nano ~/.bashrc

