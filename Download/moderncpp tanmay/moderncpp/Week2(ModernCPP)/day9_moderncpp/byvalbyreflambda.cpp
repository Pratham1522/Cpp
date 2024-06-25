#include<iostream>
#include<functional>

void solve(int a,int b,int c){
    std::cout<<a-b-c<<"\n";
}


int main()
{
   int m = 0;
   int n = 0;
   [=] (int a) mutable { m = ++n + a;
   std::cout << m << std::endl << n << std::endl; }(4);
   //std::cout << m << std::endl << n << std::endl;

    auto F1 = std::bind(solve,std::placeholders::_2,std::placeholders::_3,std::placeholders::_1);
    F1(1,2,3);
}
