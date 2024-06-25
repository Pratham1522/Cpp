#include "Functionalities.h"

void CreateObjects(Container &data)
{
    data.push_back(Car(100,std::make_shared<Vehicle>(100,"tanmay")));
}

void Print(Container &data)
{
    for(Car &obj:data){
        std::cout<<obj;
        std::cout<<"\n";
    }
}
