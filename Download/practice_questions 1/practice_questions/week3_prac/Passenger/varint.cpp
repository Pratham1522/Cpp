#include<iostream>
#include<variant>
#include<vector>

using VType = std::variant<int,std::string>;
using Container = std::vector<VType>;

int main(){
    Container data;
    data.push_back(1);
    data.push_back(12);
    data.push_back(7);
    for(VType& val:data){
        std::visit([&](auto&& v){std::cout<<v<<" ";},val);
    }
    std::cout<<"\n";
    for(VType& val:data){
        if(std::holds_alternative<int>(val)){
            std::cout<<std::get<0>(val);
        }
    }
}