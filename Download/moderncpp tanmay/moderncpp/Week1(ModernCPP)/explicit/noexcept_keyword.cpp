#include <iostream>

void fn() noexcept {
    int n1 = 10;
    std::cout<<"output is: "<<n1;
    throw "";
}
//noexcept means there is no need for extra exception handling

int main(){
    
}