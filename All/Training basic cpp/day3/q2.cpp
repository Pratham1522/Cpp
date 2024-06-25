#include<iostream>
using namespace std;

class A{
    int id;

    public:
    A(int i){id=i;}
    A(){id=0;}
    void print(){cout<<id<<endl;}
};
int main(){
    A a[2];
    a[0].print();
    a[1].print();
}

//if we define our own constructor compiler wont provide a default contructor.