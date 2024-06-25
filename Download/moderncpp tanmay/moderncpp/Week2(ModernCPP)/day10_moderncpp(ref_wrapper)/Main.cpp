#include<iostream>
#include "Functionalities.h"

int main(){
    EmpContainer data;
    ProjectContainer data1;
    CreateObjects(data,data1);
    std::cout<<IsContainerAll50KAboveSalaryEmployees(data)<<"\n";
    CalculateTaxBasedOnFormula(data,[](std::shared_ptr<Employee> emp){return emp->getSalary();});

    // auto f1= [](int num){std::cout<<num*num<<"\n";};
    // auto f2= [](int num){std::cout<<num*num*num<<"\n";};
    // Container fn{f1,f2};
    // Adaptor(10,fn);
    printEmp(data);
    for(auto& obj:data1){
        std::cout<<obj<<"\n";
    }
}   

