#include<iostream>

void F1(){
    int n1 = 10;
    int n2 = 20;

    //option 1
    auto f1 = [](int n1,int n2){
        std::cout<<n1+n2<<std::endl;
    };
    f1(n1,n2); //works!!

    //f2 captures all variables from the scope of its enclosing function 'Outer"
    //which meanas n1 and n2 are both accessbile inside f2(by reference)
    auto f2 = [&](){
        std::cout<<n1+n2<<std::endl;
    };
    f2();

    //option3: capture enclosing varibales by "value". mutable keyword allows data to be 
    //modified inside n1 and n2 but changes will not reflect outside f3.
    auto f3 = [&]() {
        n1 = 10;
        n2 = n1;
        std::cout<<n1+n2<<std::endl;
    };
    f3();
    std::cout<<n1<<n2<<"\n";

    //capture specific variables by their name using "refernece" semantics
    auto f4 = [&n1,&n2](){
        std::cout<<n1+n2<<std::endl; //this line gives error as n2 is unknown but works if we add n1 and n2 in [].
    };
    f4();

    //n1 is captured by ref and f1 is captured by value (f1 copied into f5).
    auto f5 = [&n1,f1](){
        f1(10,n1); //n3 captured reference, n2 is not accessible.
    };
    f5();
}

// int main(){
//     F1();
    
// }

//std func wrapper
//lambda functions all types
//reference wrapper
//std::ref
//std::bind
