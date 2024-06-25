#include<iostream>

void f1(int);
void f2(const int);
void f3(int&);
void f4(int&&);

int main(){
    /*objective: design a function so that accepts a
     value of type int and displays sqaure of number*/

    /* scenario 1 : Design function so that it accepts both lvalues and rvalues .
    lvalues should get copied, rvalues should be assigned. value should
     remian modifiale in the function */
    int n=10;
    f1(10);
    f1(n);

    f2(7);

    f3(n);
    //f(3) notallowed

    f4(8);
    //f4(n) notalwoed
}

void f1(int value){
    std::cout<<value*value<<"\n";
}

void f2(const int value){
        std::cout<<value*value<<"\n";
}

/* scenario 3 : accept lvalues only. rvalues are not allowed value should be
modifiable in the function */

void f3(int& value){
    std::cout<<value*value<<"\n";
} 

/* secanrio 4 : accept rvalues only by assignment value should be modifiable 
, no lvaluescraeted rvalues durectuky inside f4 by assignning rvalue to 
"value variable" */

void f4(int&& value){ //modern c++
    std::cout<<value*value<<"\n";
    value = 11;
}



/* scenario 5 : i want lvalues and rvalues both value to not be modifiable. 
lvalues should be taken by reference*/

void f5(const int& value){
    std::cout<<value*value<<"\n";
}

void f6(const int&& value){
    std::cout<<value*value<<"\n";
}








