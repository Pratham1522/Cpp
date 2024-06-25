#include "Functionalities.h"

void Square(inputContainer& inputArr, resultContainer& result){
    for(int i=0;i<5;i++){
        result[i] = inputArr[i]*inputArr[i];
    }
}
void MapThreadsToFunctions(ThreadsArray &th,inputContainer& inputArr, resultContainer& result)
{
    auto itr = th.begin();
    *itr++ = std::thread(&Square,std::ref(inputArr),std::ref(result));
    *itr++ = std::thread(&Cube,std::ref(inputArr),std::ref(result));
    *itr++ = std::thread(&Factorial,std::ref(inputArr),std::ref(result));

    for(int i=0;i<3;i++){
        if(th[i].joinable()){
            th[i].join();
        }
    }
}

void Cube(inputContainer &inputArr, resultContainer &result)
{
    for(int i=5;i<10;i++){
            result[i] = inputArr[i-5]*inputArr[i-5]*inputArr[i-5];
        }
}
void Factorial(inputContainer& inputArr, resultContainer& result){
    for(int i=0;i<5;i++){
        int product=1;
        for(int j=1;j<=inputArr[i];j++){
            product*=j;
        }
        result[i+10]=product;
    }
}

void Display(resultContainer &result)
{
    for(int val:result){
        std::cout<<val<<" ";
    }
}

void Input(inputContainer &inputArr)
{
    std::cout<<"enter 5 numbers: ";
    int count=0;
    int val=-1;
    while(count!=5){
        std::cin>>val;
        if(val<0 || val>10){
            continue;
        }
        inputArr[count]=val;
        count++;
    }
}
