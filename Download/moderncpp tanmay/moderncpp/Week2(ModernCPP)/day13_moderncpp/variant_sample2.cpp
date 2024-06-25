#include "Employee.h"
#include "BusinessOwner.h"
#include<memory>
#include<variant>
#include<list>

using EmPtr = std::shared_ptr<Employee>;
using BusinessPtr = std::shared_ptr<BusinessOwner>;
using VType = std::variant<EmPtr,BusinessPtr>;

using Container = std::list<VType>;

void CreateObjects(Container &data){
    data.push_back(std::make_shared<Employee>("tan",12345.0f));
    data.push_back(std::make_shared<BusinessOwner>("abc",99345.0f,12345.0f));
}

void PrintTax(Container &data){
    for(VType& v:data){
        std::visit(
            [](auto&& val){val->payTax();},v
        );
    }
}

//function to print revenue of all business owners in data
void ShowRevenue(Container &data){
    /* for every VType variable codenamed "v" which is present in data,
    a) cehck if v holds the alternative of type businessptr
        -if yes, since busiptr is at posi 1 in VType, use std::get<1>(V) posi pointer to fetch that type. */
    for(VType& v:data){
        if(std::holds_alternative<BusinessPtr>(v)){
            std::cout<<"revenue is: "<<std::get<1>(v)->revenue()<<"\n";
        }
    }
}

int main(){
    Container data;
    CreateObjects(data);
    PrintTax(data);
    ShowRevenue(data);
}
