#include<unordered_map>
#include<iostream>
#include "Employee.h"
#include<memory>


using StackObject = std::unordered_map<std::string,Employee>;
using RawPointerObject = std::unordered_map<std::string,Employee*>;
using EmpPtr = std::shared_ptr<Employee>;
using SmartPointerObject = std::unordered_map<std::string,EmpPtr>;

void CreateObjects(StackObject& data){
    data.emplace(std::make_pair("emp101",Employee("emp101","tanmay",2348723.0f,22,"pune")));
    data.emplace(std::make_pair("emp102",Employee("emp101","john",14873.0f,22,"pune")));
    data.emplace(std::make_pair("emp102",Employee("emp101","abel",2348723.0f,22,"pune")));
}

void CreateObjects(RawPointerObject& data){
    std::make_pair("emp10",new Employee("emp10","tanmay",2348723.0f,22,"pune"));
    std::make_pair("emp11",new Employee("emp11","john",2318723.0f,22,"pune"));
    std::make_pair("emp12",new Employee("emp12","abel",8348723.0f,22,"pune"));
}
void CreateObjects(SmartPointerObject& data){
    std::make_pair<std::string,std::shared_ptr<Employee>>("emp1",std::make_shared<Employee>("emp1","tanmay",2348723.0f,22,"pune"));
    std::make_pair<std::string,std::shared_ptr<Employee>>("emp2",std::make_shared<Employee>("emp2","alice",148723.0f,22,"pune"));
    std::make_pair<std::string,std::shared_ptr<Employee>>("emp3",std::make_shared<Employee>("emp3","ben",4348723.0f,22,"pune"));
    
}
template<typename T>
void Display(T& data){
    for(auto& [k,v]:data){
        std::cout<<k<<" "<<v<<"\n";
    }
}

int main(){
    StackObject data1;
    RawPointerObject data2;
    SmartPointerObject data3;
    CreateObjects(data1);
    CreateObjects(data2);
    CreateObjects(data3);
    Display<StackObject>(data1);
    Display<RawPointerObject>(data2);
}

//compile time template argument deduction : you can deduce template parameters for template functions for cpp14
