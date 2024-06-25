/* 

 */

#include<iostream>


bool isEven(int number){
    return number%2==0;
}

int main(){
    std::cout<<"hello\n";
    // bool ans = isEven(5);
    //if(ans)
    //To remove the useless variable ans which is used only once then we use if initializer
    if(bool ans = isEven(5);ans)
    {
        std::cout<<"number is even\n";
    }
    else{
        std::cout<<"number is odd\n";
    }
}
