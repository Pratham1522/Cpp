#include<iostream>

enum shape { circle, square=4, hexagon=6};

int main(){
    int code=4;
    switch(code){
        case circle:
        std::cout<<"circle";
        break;
        case square:
        std::cout<<"square";
        break;
        case hexagon:
        std::cout<<"hexagon";
        break;
    }
    std::cout<<"\n";

}