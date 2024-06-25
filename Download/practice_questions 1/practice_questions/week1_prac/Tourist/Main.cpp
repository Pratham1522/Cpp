#include "Functionalities.h"
#include "Permit.h"

int main(){
    Container data;
    createObject(data);
    // find(data);
    findaverage(data);
    findmaximum(data);
    std::vector<TouristVehicle*> v1 = find(data);
    for(auto obj:v1){
        std::cout<<*obj<<std::endl;
    }    
DeleteObjects(data);


unsigned int n;
std::cout<<"enter cab,bike or bus\n";
std::cin>>n;
TouristVehicleType t1 {TouristVehicleType::BUS};
switch(n){
    case 0:
        t1=TouristVehicleType::CAB;
        break;
    case 1:
        t1=TouristVehicleType::BUS;
        break;
    case 2:
        t1=TouristVehicleType::BIKE;
        break;
    default :
    t1=TouristVehicleType::BUS;
}


/*     sample p;
    std::cout<<p; */
}

//point of type of pointers? is it stored in heap as per class?? or DT??
//FRIEND func is friend of that class what if there are 2 classes in 1 file and if we dont use scope resolution with that class 
//how can we identify the output is frmo that class