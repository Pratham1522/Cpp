#include "Functionalities.h"

int main(){
    Container data;
    CreateOjects(data);
    std::cout<<CheckCondition(data)<<"\n";
    std::cout<<CalculateDiscountPrice(data, Devicetype::MOBILE)<<"\n";
    DeleteObjects(data);
}