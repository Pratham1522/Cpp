#include<iostream>

int main(){
    int **arr;
    int r=2,c=2;
    arr = new int*[r*4];
    for(int i=0;i<r;i++){
        arr[i] = new int[c*4];
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            std::cin>>arr[i][j];
        }
    }
    for(int i=0;i<r;i++){
        for(int j=0;j<c;j++){
            std::cout<<arr[i][j];

        }
        std::cout<<"\n";
    }
}