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
    data.push_back(std::make_shared<BusinessOwner>("abc",99345.4f,12345.0f));
}

void PrintTax(Container &data){
    for(VType& v:data){
        std::visit(
            [](auto&& val){val->payTax();},v
        );
    }
}

void ShowRevenue(Container &data){
    for(VType& v:data){
        if(std::holds_alternative<BusinessPtr>(v)){
            std::cout<<"revenue is: "<<std::get<1>(v)->revenue()<<"\n";
        }
    }
}

/* find average revenue for all business owners in our data container */
void AverageRevenue(Container &data){
    if(data.empty()){
        throw ;
    }
    float average=0.0f;
    std::size_t count=0;
    for(VType& obj:data){
        if(std::holds_alternative<BusinessPtr>(obj)){
            average += std::get<1>(obj)->revenue(); 
            count++;
        }
    }
    std::cout<<"average of revenue is: "<<static_cast<float>(average/count)<<"\n";
}

//cehck if all sal is above 60k

void isSetOfEmployeeSalAbove60K(Container &data){
    int flag=0;
    for(VType& obj:data){
        if(std::holds_alternative<EmPtr>(obj)){
            if(std::get<0>(obj)->salary()<60000.0f){
                int flag=1;
                break;
            }
        }
    }
    if(flag==0){std::cout<<"yes all employees ahve salary above 60000\n";}
    else{std::cout<<"no all employees ahve salary above 60000\n";}
    //or std::cout<<"status check complete: "<<std::boolaplha<<flag;
}

int main(){
    Container data;
    CreateObjects(data);
    PrintTax(data);
    ShowRevenue(data);
    AverageRevenue(data);
    isSetOfEmployeeSalAbove60K(data);
}
