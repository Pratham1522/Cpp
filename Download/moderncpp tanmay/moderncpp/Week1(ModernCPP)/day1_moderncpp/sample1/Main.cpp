#include "Functionalities.h"

int main(){
    Container data;
    CreateObjects(data);
    std::cout<<AverageAccountBalance(data)<<std::endl;   
    deleteobjects(data);
}
