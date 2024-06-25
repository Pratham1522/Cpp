#include<iostream>
using namespace std;

int main(){
    int a=10;
    int *id;
    id=&a;       //only pointer stores address
    cout<<"id is "<<*id<<"\n";   //*pointer returns the value stored at address.

    char* const ptr1="GOOD";  //constant pointer ,cannot point to any other variable
    int const *ptr2=&a;      //pointer to a constant ,cannot change value through pointer.

    const char* const ptr3="xyz"; //constant pointer to a constant,

    //refernence variable : another name for variable
    int &b=a;
    a=20;
    cout<<"b = "<<b<<"\n";
    //application passing reference to functions.
    /*
    void fun(&x){
        x+=19;
    }
    int main(){
        int m=5;
        fun(m);
        cout<<m;
    }
    */

}
// Segmentation fault (core dumped) means that you tried to access memory that you do not have access to