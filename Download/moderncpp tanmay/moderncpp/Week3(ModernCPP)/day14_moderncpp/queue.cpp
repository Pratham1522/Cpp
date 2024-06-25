#include<iostream>
#include<stack>
#include<vector>

int main(){
    std::stack<int>st;
    st.push(1);
    st.push(2);
    st.push(3);
    std::cout<<st.top()<<"\n";
    st.pop();
    std::cout<<st.top()<<"\n";
    st.pop();
    std::cout<<st.top()<<"\n";
    st.pop();
    
}
/* 
mcq 25
m1 10
m2 0
m3 25
m4 0
 */
