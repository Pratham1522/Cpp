#include<iostream>
using namespace std;

class Vector{
    int* arr;
    int size;
    int capacity;

    public:
    Vector(int c=5){
        size=0;
        capacity=c;
        arr=new int[capacity];
    }
    ~Vector(){
        delete[] arr;
    }
    void resolve(){
        capacity*=2;
        int *t =new int[capacity];
        for(int i=0;i<size;i++){
            t[i]=arr[i];
        } 
        delete[] arr;
        arr=t;
    }
    void push(int ele){
        if(size <capacity){
            arr[size]=ele;
            // cout<<"pushed"<<size<<"\n";
        }else if(size == capacity){
            // cout<<"resolved"<<"\n";
            resolve();
            arr[size]=ele;
        }
        size++;
    }
    void print(){
        cout<<"Array is : ";
        for(int i=0;i<size;i++){
            cout<<arr[i]<<" ";
        }
        cout<<"\n";
    }
};
int main(){
    Vector obj(3);
    for(int i=1;i<6;i++){
        obj.push((10*i));
    }
    obj.print();
    for(int i=1;i<6;i++){
        obj.push((50+(10*i)));
    }
    obj.print();
}