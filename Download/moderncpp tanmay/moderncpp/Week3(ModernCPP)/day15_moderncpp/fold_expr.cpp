#include<iostream>

template<typename... T>
auto Magic(T... args){
    return (...-args);
}

int main(){
    std::cout<<Magic(1,-1,-2,4,7)<<"\n";
}
