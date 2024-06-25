#include<iostream>
#include "Functionalities.h"

int main(){
    Container data;
    CreateObjects(data);
    // FindVehicleOnID(data,12345);
    // FindVehicleDetailsOnType(data,Type::SUV);
    // Container solution = FindLastNInstance(data,2);
    // for(Owner* obj:solution){
    //     PrivateVehicleOwner *pptr = dynamic_cast<PrivateVehicleOwner*>(obj);
    //     if(pptr!=nullptr){
    //         std::cout<<*pptr<<std::endl;
    //     }
    //     CommercialOwner *cptr = dynamic_cast<CommercialOwner*>(obj);
    //     if(cptr!=nullptr){
    //         std::cout<<*cptr<<std::endl;
    //     }
    // }
    // FindMinimum_Average_Maximum(data);
    // FindDetailsOfCommercialOwner(data);
    // std::cout<<std::endl;
    // std::cout<<std::endl;
    Print(data);
    DeleteObjects(data);
}