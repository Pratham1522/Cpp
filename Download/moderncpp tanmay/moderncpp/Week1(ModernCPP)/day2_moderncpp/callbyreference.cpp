#include<iostream>

void solve(int& a){
    std::cout<<&a<<"\n";
    a=10;
}

int main(){
    int a=3;
    std::cout<<&a<<"\n";
    solve(a);
    std::cout<<a;
}
