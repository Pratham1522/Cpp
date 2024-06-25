#include "Functionalities.h"

std::function<bool( int)> PredicateToFindOddNumbers = [](int number)->bool{
    if(number%2!=0){
        return true;
    }
    return false;
};

std::function<bool( int)> PredicateToFindDivBy4 = []( int number)->bool{
    if(number%4==0){
        return true;
    }
    return false;
};


std::function<bool( int)> PredicateToFindNegativeNumbers = []( int number)->bool{
    if(number<0){
        return true;
    }
    return false;
};

std::function<bool(int)> BindPredicateToFindNegativeNumbers = std::bind(PredicateToFindNegativeNumbers,-7);

// void Adaptor(Container &data, std::function<bool(int)> predicate)
// {
//     if(data.empty()){
//         throw std::runtime_error("data is empty!!\n");
//     }
//     bool flag=false;
//     for(int num:data){
//         if(predicate(num)){
//             flag=true;
//             std::cout<<num<<" ";
//         }
//     }
//     std::cout<<"\n";
//     if(flag==false){
//         throw std::runtime_error("no data to be filtered.\n");
//     }
// }

void Adaptor(Container &data, FnContainer& functions){
    // for(auto fns : functions){
    //     for(int num:data){
    //         if(fns(num)){
    //             std::cout<<num<<" \n";
    //         }
    //     }
    // }
    if(functions[3](data[0])){
        std::cout<<"The number is negative!!\n";
    }
}