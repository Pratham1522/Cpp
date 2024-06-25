#include<iostream>
#include<functional>
#include<vector>

/* 
    I want to design an adaptor that accepts 
    a) a vector of integers
    b) a logic that works in a single item at a time.
        this logic should "filter" the input data and only display values which satisfy the requirements of the logic
        eg: from a vector of 1,2,3,4,5. logic of "even numbers" should only display 2 and 4.
*/

void Adaptor(const std::vector<int>& data, std::function<bool (int)>  fn){
    for(int val:data){
        if(fn(val)){
            std::cout<<val<<"\n";
        }
    }
}


int main(){
    Adaptor(
        std::vector<int> {1,2,3,4,5},
    [](int number){  return number%2 == 0;   }
    );
}