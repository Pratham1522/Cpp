#include<iostream>

void add(int a){
    std::cout<<"add";
}
void magic(int a){
    std::cout<<"magic";
}

void operation(int arr[], int size, void (*ptr)(int)){

}
int main(){
    int arr[]={1,2,3};
    operation(arr,3,&add);
    operation(arr,3,&magic);
}