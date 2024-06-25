/* 
objective: a function that finds first n valies from input container
 */

/* 
    scenario 1: input is valid, n is also valid
    scenario 2: input is invalid, n is valid
    scenario 3: input is valid, n is invalid (too large or negative nums or 0)
*/

#include<vector>
#include<iostream>
#include "ContainerEmptyException.h"

void Magic(const std::vector<int>& data, const int N){
    //scenario 2:input is invalid and n is valid
    if(data.empty()){
        //MARK THIS AS A BAD SITUATION
        throw ContainerEmptyException("data not there");
    }
    else if(N<=0 || N>data.size()){
        throw std::runtime_error("n is invalid");
    }
}

int main(){

    std::vector<int> data {10,20,30,40};
    try{
    Magic(data, 3);
    }
    catch(std::runtime_error& ex){
        std::cerr<<ex.what();
    }
    catch(std::runtime_error& ex){
        std::cerr<<ex.what()<<"\n";
    }
}

/* 
    CPP way of handling "bad things happened"
    std::logical  error
    std::runtime_error
    std::bad_cast_error
    std::bad_alloc
*/

/*
    Exceptions: a situation which is not avoidable which cannot be prevented happens due to 
    circumstances beyond a deelopers control but can be resolved based on "AN ACTION PLAN"

    Errors: something that happens due to programmers fault. Can be avoided by improving code
*/
/* 
We call fuction... function throws exception --->{make object, capture users message inside the obj, c
reate a mechanism to extract this msg, done!}
 */