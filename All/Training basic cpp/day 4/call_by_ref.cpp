#include<iostream>
using namespace std;

void swap(int &a,int &b){ //giving referance as parameter.
    int temp=a;    //temp=5
    a=b;           //a=4
    b=temp;        //b=5
}

void swap1(int *a,int *b){  
    int t;          
    t= *a;             //t=value store at &a=5
    *a=*b;
    *b=t; 
}
int main(){
    int a=5,b=4;
    swap1(&a,&b);     //function call
    cout<<a<<" "<<b<<"\n";
}