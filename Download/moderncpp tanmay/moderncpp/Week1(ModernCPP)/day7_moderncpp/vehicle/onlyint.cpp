#include<iostream>
#include<limits>

int main(){
    int n;
    std::cin>>n;
    if(std::cin.fail()){
        std::cout<<"enter input";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
    }
    int x;
    std::cin>>x;
    std::cout<<x;
}
