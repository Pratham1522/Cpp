#include <iostream>
using namespace std;

void /*returntype : output*/ function_name(/*Parameter list : input*/){
    cout<<"Hello";
}

//function overloading , we can call fun with same name and diff parameters.
//overloading : diff no. of para, diff para types, diff para order,const keywords.
//returntype is not considered in funciton overloading.

//function Templates(Generic function : Generalised) : use if logic of 2 fun is same only DT is diff.
template<class T>//t define of class template
T max(T x ,T y){   // t can become int or float based on function call.
    if(x>y){return x};
    else {return y};
}
//use default args to reduce function overloading.(combine overloaded function)
//start making default args from end to start or right to left.

//Parameter Passing methods
/*
1.Pass/Call by value.  : send actual values,get in formal, perform operation return result.
2.Pass/Call by reference.   : send actual, get in addresses .
3.Pass/Call by address.   : send addresses ,formal args are pointers
*/

void swapByAddress(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
    //call as : swapByAddress(&x,&y);
}

void swapByReference(int &a,int &b){
    int temp=a;
    a=b;
    b=temp;
    // call by swapByReference(x,y);
}//best no memory for pointer required.(no activation for function needed)
//no function in machine code, function will be part of main function. function call code replaced by function code.
//also callled inline function.

//return by address
int* fun(int size){
    int *p=new int [size];  //note returning address must be of heap memory. 
    for(int i=0;i<size;i++){
        p[i]=i+1;
    }
    return p;
    //call: int *ptr=fun(6);
}
int& fun(int &x){
    return x;  //returning refernce to a again
    //call
     /* int a=10;
        fun(a)=25     //whole fun(a) becomes a and a=25;
        cout<<a;   
    */
}

//static variable : lifetime till program ends but only accessible within function scope.
//global variable : lifetime till program ends ,scope accessible in all functions.
//local variable : lifetime till function executes, scope within function scope.


// hw: linear search using fucntion ,pass array as arg to function.


int main(){
    function_name();
    //good practice, cin cout using main function only
    return 0;
}