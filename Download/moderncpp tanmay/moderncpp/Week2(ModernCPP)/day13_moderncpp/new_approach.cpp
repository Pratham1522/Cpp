#include<thread>
#include<iostream>
#include<array>

using Container = std::array<int,12>;
using ResultContainer = std::array<int,12>;

void solve(Container& data, ResultContainer& result){
    int k=0;
    int range = data.size()/k;
    if(data.size()%4==0){
        for(int i=k;i<range;i++){
            result[i] = data[i]*data[i];
        }
    }
    else{
        if(k>data.size()){
            for(int i=k;i<k+range;i++){
                result[i] = data[i]*data[i];
            }
            k+=range;
        }
        else{
            for(int i=k;i<k+range;i++){
                result[i] = data[i]*data[i];

                k+=range;
            }
        }
    }
}

int main(){
    Container data {1,2,3,4,5,6,7,8,9,10,11,12};
    ResultContainer result;
    // std::thread t1(&solve,data,result,0,3);
    // std::thread t2(&solve,data,result,3,6);
    // std::thread t3(&solve,data,result,6,9);
    // std::thread t4(&solve,data,result,9,12);
    // if(t1.joinable()){t1.join();}
    // if(t2.joinable()){t2.join();}
    // if(t3.joinable()){t3.join();}
    // if(t4.joinable()){t4.join();}
    solve(data,result,0,3);
    solve(data,result,3,6);
    solve(data,result,6,9);
    solve(data,result,9,12);
    for(int obj:result){
        std::cout<<obj<<" ";
    }
}
