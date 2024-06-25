#include<iostream>
#include<vector>


template <typename T>
void Display(std::vector<T>& data){
    for(T obj:data){
        std::cout<<obj<<"\n";
    }
}

template <typename T>
T add(T n1){
    return n1;
}

template <typename T, typename... Remaining>
T add(T n1, Remaining... args){
    return (n1 + add(args...));
}

/* 
 how to create type-agnostic (type independent) logic
 that can apply an operator on 0 or more arguments by using recursion as its problem solving technique
 eg: add 1 or more numbers
 eg: use * oepraotr on 1 or more values.
*/

int main(){
    // std::vector<int> v1 {1,2,3,4,5};
    // std::vector<std::string> v2 {"abc","bcd"};
    // Display(v1);
    // Display<std::string>(v2);
    std::cout<<add<int>(1,2,3,4,5)<<"\n";
    
}

/* Problem : A situation which requires a particular algorithm to find its solution
    eg: searching a number...
    Problem Solving Techniques:
        1) give up
        2) iterative approach
        3) divide and conquer
        4) recursion : divide the problem into sub problems till a well known fully solved sub 
        problem appears, then you reverse the chain and solve the whole problem.
 */

