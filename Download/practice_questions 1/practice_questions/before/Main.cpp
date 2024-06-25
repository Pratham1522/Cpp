#include "Functionalities.h"

int main()
{
    try
    {
        Container data;
        CreateObjects(data);
        std::cout << FindID(data);
        // Container answer = FindInstanceOfSameType(data, CustomerType::VIP);
        // for (Customer *obj : data)
        // {
        //     std::cout << *obj;
        // }
        // FindSumOfHigeshtAndLowest(data);
         //*data[0] + *data[1];
        // FindInstanceOfSameType(data,CustomerType::VIP);
        // for(auto obj:data){
        //     std::cout<<*obj<<"\n";
        // }

        DeleteObjects(data);
    }
    catch(VectorEmptyException &ex){
        std::cout<<ex.what();
    }
}
