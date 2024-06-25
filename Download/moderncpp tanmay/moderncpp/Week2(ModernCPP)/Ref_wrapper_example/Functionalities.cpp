#include "Functionalities.h"

void CreateObjects(Container &data,InvoiceContainer& inv)
{
    inv.push_back(Invoice("123",InvoiceType::EBILL,23));
    inv.push_back(Invoice("123",InvoiceType::EBILL,23));

    inv.push_back(Invoice("123",InvoiceType::EBILL,23));

    data.push_back(std::make_shared<Bill>(111,std::move(inv[0])));
    data.push_back(std::make_shared<Bill>(222,std::move(inv[1])));
    data.push_back(std::make_shared<Bill>(333,std::move(inv[2])));
}

std::function<float(Container&)> HighestBillAmount = [](Container &data)->float{
    float highest = data[0]->billAmount();
    for(std::shared_ptr<Bill>& obj:data){
        if(obj->billAmount()>highest){
            highest = obj->billAmount();
        }
    }
    return highest;
};

std::function<Container(Container&,int)> FindNInstance = [](Container &data, int N)->Container{
    Container result;
    int count=0;
    for(std::shared_ptr<Bill>& obj:data){
            result.push_back(obj);
            count++;
}
return result;
};

std::function<Container(Container&,int)> BindNInstace = std::bind(FindNInstance,std::placeholders::_1,1);
