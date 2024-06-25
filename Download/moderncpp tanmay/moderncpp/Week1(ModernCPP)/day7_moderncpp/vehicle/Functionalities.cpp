#include "Functionalities.h"

void CreateObjects(Container &data)
{
    data.push_back(new PrivateVehicleOwner("tanmay", "pune",
                                           new Vehicle(1234, "xuv300", Type::SUV, 100000, 7, "mahindra", FuelType::PETROL, TransmissionType::MANUAL), 11111111));
    data.push_back(new PrivateVehicleOwner("abcd", "pune",
                                           new Vehicle(12345, "thar", Type::SUV, 5500, 6, "mahindra", FuelType::PETROL, TransmissionType::AUTOMATIC), 123235));
    data.push_back(new CommercialOwner("abcd", "pune",
                                       new Vehicle(123, "thar", Type::SUV, 10000, 6, "mahindra", FuelType::PETROL, TransmissionType::AUTOMATIC), 8374));
}

void DeleteObjects(Container &data)
{
    for (Owner *obj : data)
    {
        if (obj)
        {
            if(obj->vehicle())
            delete obj->vehicle();
        }
        delete obj;
    }
}

void FindVehicleOnID(Container &data, int id)
{
    for (Owner *obj : data)
    {
        if (obj->vehicle()->id() == id)
        {
            std::cout << *obj->vehicle() << std::endl;
        }
    }
}

void FindMinimum_Average_Maximum(Container &data)
{
    float average=0.0f, maximum = 0.0f, minimum = 100000.0f;
    for(Owner* obj:data){
        average += obj->PayRegisterationCharges();
        if(obj->PayRegisterationCharges()>maximum){
            maximum = obj->PayRegisterationCharges();
        }
        if(obj->PayRegisterationCharges()<minimum){
            minimum = obj->PayRegisterationCharges();
        }
    }
    std::cout<<"average is : "<<average/data.size()<<"\n";
    std::cout<<"maximum is: "<<maximum<<"\n"<<"minimum is: "<<minimum<<"\n";
}

void FindVehicleDetailsOnType(Container &data, Type type)
{
    for (Owner *obj : data)
    {
        if (obj && obj->vehicle()->type() == type)
        {
            std::cout << *obj->vehicle() << std::endl;
        }
    }
}

Container FindLastNInstance(Container &data, int n)
{
    Container solution;
    int count = 0;
    for (Container::reverse_iterator itr = data.rbegin(); itr != data.rend(); ++itr)
    {
        if (count < n)
        {
            solution.push_back(*itr);
            count++;
        }
    }
    return solution;
}

void FindInstacesOverThreshold(Container &data)
{

}

void FindDetailsOfCommercialOwner(Container &data){
    for(Owner* obj:data){
        CommercialOwner *temp=dynamic_cast<CommercialOwner*>(obj);
        if(temp !=nullptr){
            std::cout<<*temp->vehicle();
        }
        else{
            std::cout<<"dynamic cast failed.\n";
        }
    }
}

void Print(Container &data)
{
    for(auto obj:data){
        PrivateVehicleOwner *ptr = dynamic_cast<PrivateVehicleOwner*>(obj);
        if(ptr!=nullptr){
            std::cout<<*ptr<<"\n";       
        }
        CommercialOwner *cptr = dynamic_cast<CommercialOwner*>(obj);
        if(cptr!=nullptr){
            std::cout<<*cptr<<"\n";
        }
    }
}

/*
    rule 1: debugger is not on 1 file but whole project

*/
