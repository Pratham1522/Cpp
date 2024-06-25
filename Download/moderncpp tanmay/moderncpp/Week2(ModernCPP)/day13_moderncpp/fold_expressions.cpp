#include<iostream>
#include<algorithm>
#include<vector>

/* 
    i take infinite parameters
    i use nfinite params with + operator
*/

/* 
 i accept 0 or more arguments, each argument of type T i need to add n1(first parameter) 
 with the remaining parameters
*/

template <typename... T>
int add(T... n1){
    // return (n1 + ...);// operation is right associatuve (rightmost bracket pehle!!)
    int sum=0;
    std::for_each(n1.begin(),n1.end(),[&](T num){
        sum += num;
    });
    return sum;
}

int main(){
    // std::vector<int> v1 {1,2,3,4,5};
    // std::vector<std::string> v2 {"abc","bcd"};
    // Display(v1);
    // Display<std::string>(v2);
    // std::cout<<add<int>(1,2,3,4,5)<<"\n";
    std::vector<int> v1 = {1,2,3};
    std::vector<int> v2 = {4,5,6};
    std::vector<int> v3 = {7,8,9};
    std::cout<<add(v1,v2,v3);
}

