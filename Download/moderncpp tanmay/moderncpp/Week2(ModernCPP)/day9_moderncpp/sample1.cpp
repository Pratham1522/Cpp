#include<iostream>
#include<vector>
#include<functional>

void Cube(const std::vector<int>& data){
    if(data.empty()){
        throw std::runtime_error("data is empty.\n");
    }
    for(int val : data){
        std::cout<<val*val*val<<"\n";
    }
}

void Square(const std::vector<int>& data){
    if(data.empty()){
        throw std::runtime_error("data is empty.\n");
    }
    for(int val : data){
        std::cout<<val*val<<"\n";
    }
}

/* 
    adaptor is a function which takes 2 parameters
    a) constant lvalue reference to a std::Vector of integers
    b) a function wrapper which wraps a function of following signature
        -accept one const lvalue refernce to a vector of integers
        -returns void
    Adaptor also returns void.
*/

void Adaptor(const std::vector<int>& data, std::function<void (const std::vector<int>&)>  fn){
    if(data.empty()){
        throw std::runtime_error("data is epmty.\n");
    }
    fn(data);
}

int main(){
    //void (*ptr) (const std::vector<int>&) = &Square;
    //void (*ptr2) (const std::vector<int>&) = &Cube;

    Adaptor({1,2,3},&Square);
    Adaptor({1,2,3},&Cube);
}

/* 
    Scenario: 
    BMW: Workshop engineers:
    ---->diagnostics
        Functions(carUnit, logic to test diagnostics)
*/
