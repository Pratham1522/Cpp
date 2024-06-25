#include<iostream>
#include<optional>

/* i have a container of employees 
        -id, name ,sal 
        i want a func that returns a container of all emp with sal > 50k
        
        - scenario 1: input data is invalid (empty)
            -exceptions
        - scenario 2: input is valid, atleast 1 employee above 50k salary exists
            -make container push in the container and return container.
        - scenario 3: input valid but no employee has sal above 50k
            -return empty result container.
            -exception (is it really an exception??)
            - may or may not return something
        */
#include "Employee.h"
#include<vector>
#include<memory>

using Container = std::vector<std::shared_ptr<Employee>>;

void CreateObject(Container &data){
    data.push_back(std::make_shared<Employee>("tanmay",1000000.0f));
    data.push_back(std::make_shared<Employee>("tan",20000.0f));
    data.push_back(std::make_shared<Employee>("john",1000.0f));
}

std::optional<Container> FindAbove50K(Container& data){
    if(data.empty()){
        throw ;
    }
    Container result;
    for(std::shared_ptr<Employee>& obj:data){
        if(obj->salary()>50000){
            result.push_back(obj);
        }
    }
    if(result.empty()){
        return std::nullopt;//nullopt means nothing to show, nothing to return
    }
    return result;
}

int main(){
    Container data;
    CreateObject(data);
    std::optional<Container> result = FindAbove50K(data);
    if(result.has_value()){
        Container actual_result = result.value();
        for(auto obj:actual_result){
            std::cout<<obj;
        }
    }
}
