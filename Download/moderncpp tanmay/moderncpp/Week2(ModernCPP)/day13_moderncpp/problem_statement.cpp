/* 
    12 numbers stored in an array 
    calculate square of each number in arr and store in a results array
    1 2 3 4 5 6 7 8 9 10 11 12 = 650?

*/

/* 
    n number of data vlaues
    x no of threads
    scenario 1: n can be divisible by x.
    scenario 2: n is not divisible by x.
    scenario 3: n is 
*/
#include<thread>
#include<iostream>
#include<array>

using DataContainer = std::array<int,13>;
using ResultContainer = std::array<int,13>;
using ThreadContainer = std::array<std::thread,7>;


void Display(ResultContainer &result){
    for(int val : result){
        std::cout<<val<<"\n";
    }
}

void Square(DataContainer& data,ResultContainer& result,int start, int end){
    for(int i=start;i<end;i++){
        result[i] = data[i]*data[i];
    }
    std::cout<<std::this_thread::get_id()<<"\n";
}

void MapThreadsToData(DataContainer& data, ThreadContainer& thArr, ResultContainer& result){
    int k=0;
    int range = data.size()/thArr.size();
    int remaining = data.size() - range*thArr.size();
    if(thArr.size()>data.size()){
        thArr[0] = std::thread(&Square,std::ref(data),std::ref(result),0,data.size());
    }
    if(data.size()%thArr.size()!=0){
        for(int i=0;i<thArr.size();i++){
            thArr[i] = std::thread(&Square,std::ref(data),std::ref(result),k,k+range);
            // Square(data,result,k,k+range);
            k += range;
        }
        Square(data,result,k,k+remaining);
    }
    else{
        for(int i=0;i<thArr.size();i++){
            thArr[i] = std::thread(&Square,std::ref(data),std::ref(result),k,k+range);
            // Square(data,result,k,k+range);
            k += range;
        }
    }
}

int main(){ 
    try{
    DataContainer data {1,2,3,4,5,6,7,8,9,10,11,12,13};
    // DataContainer data {1};
    ThreadContainer thArr;
    ResultContainer result;
    if(thArr.size()>data.size()){
        throw std::runtime_error("thread size is higher than data size");
    }
    else{
        MapThreadsToData(data,thArr,result);
        for(int i=0;i<thArr.size();i++){
            if(thArr[i].joinable()){
                // std::cout<<std::this_thread::get_id()<<"\n";
                thArr[i].join();
            }
        }
    }
    Display(result);
    }
    catch(std::exception &ex){
        std::cout<<ex.what();
    }
}

/* 
1) declare threads array and data array
2) create threads by mapping square function on 3 data val each
3) wait for all of these new threads to complete
4) after all threads are done call display and print
        OR
1) create a class with logic for square written somewhere(member function, operator overload ())
2)init one object of this class where we have memory for input data and output data
3) create mapping function to assign 3 values perthread
4) wait for all threads
5) write logic for display and show output
*/

/* 
Writing solutions happens in phases/steps:
a) interpret the problem "ACCURATELY"
b) design solution(s)
    b1) evaluate each of your solutions for feasibility
    b2) do analysis "try to find the best solution amongst all"
c) implement the soluion (start coding)
d) unit testing the solution for all possible corner cases.
e) document the solution
f) version control merge
g) assist in deployment
h) maintain the code!
*/
