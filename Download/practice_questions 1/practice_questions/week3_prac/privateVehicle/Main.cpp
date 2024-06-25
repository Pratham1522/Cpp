// #include "Operations.h"
// #include "Functionalities.h"
#include "Operations.h"

int main(){
    Container data;
    PermitContainer permits;
    Operations *obj = Operations::getInstance();
    // std::thread t1(&Operations::CreateObjects,std::ref(data),std::ref(permits));
    // std::thread t2(&Operations::ReturnAverage,std::ref(data));
    // std::thread t3(&Operations::ReturnTrueIfAllPriceAbove5L,std::ref(data));
    // std::thread t4(&Operations::Print,std::ref(data),std::ref(permits));
    // if(t1.joinable()){t1.join();}
    // if(t2.joinable()){t2.join();}
    // if(t3.joinable()){t3.join();}
    // if(t4.joinable()){t4.join();}
    // CreateObjects(data,permits);
    // Print(data);
    obj->CreateObjects();
    std::future<std::optional<PrivateContainer>>result = std::async(&Operations::FetchPrivateVehiclePointer,obj);

    std::optional<PrivateContainer> answer = result.get();//waits for result to arrive and fetches the internal data
    if(answer.has_value()){
        PrivateContainer final_data = answer.value();
        for(std::shared_ptr<PrivateVehicle>& p : final_data){
            std::cout<< p <<"\n";
        }
    }
}

