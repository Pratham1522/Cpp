#include<iostream>
#include<utility>
#include "sample.h"

int main(){
    sample s(3);
    // sample s2(s);
    sample s2=std::move(s);
    std::cout<<s;
    std::cout<<s2;
}