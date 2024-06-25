#include<iostream>
#include "Functionalities.h"

int main(){
    Container data;
    CreateObjects(data);
    std::cout<<CountOfValAbove5000(data)<<std::endl;
    CheckCardiologistAvailability(data);
    std::cout<<"\n";
    std::cout<<CheckAverageOfPatient(data)<<std::endl;
    Display(data,1);
    deleteobjects(data);
}