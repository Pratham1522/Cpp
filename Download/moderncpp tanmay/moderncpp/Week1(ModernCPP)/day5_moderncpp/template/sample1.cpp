#include<iostream>

/* 
dsiplay is a function that accepts one reference of some datatype T and use <<operator with data as rhs operand
 */
template<typename T>
void Display(T &arg ){
    std::cout<<arg<<"\n";
}

/* GENERIC PROGRAMMING: writing logic which works "generally" with all type or writing type agnostic logic! */

template<typename T, typename A>
void Add(T a, A b){
    std::cout<<a+b<<"\n";
}

// int main(){
//     int n1=10;
//     Display<int>(n1);
//     std::string _name = "tanmay";
//     Display<std::string>(_name);
//     Add(4,3.2);
//     Display("hell");
// }
