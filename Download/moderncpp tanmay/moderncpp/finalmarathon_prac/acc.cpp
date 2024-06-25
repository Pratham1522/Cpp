#include<iostream>
#include<vector>
#include<numeric>

 
int main(){ 
    std::vector<int> vec{1,2,3,4,5,6};
    int answer=std::accumulate(vec.begin(),vec.end(),1,[](int prod_upto_this,const int a){
        return prod_upto_this*a;
    });
 
    std::cout<<"The product is  : "<<answer<<std::endl;
}
