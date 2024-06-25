#include<iostream>
#include<functional>
// #include<>

/* 
    1) A function which is a one time-usable logic

    2) Normal Functions or global functions are stored in code segment they have global access level.

*/
 
void Adaptor(const std::vector<int>& number, std::function<bool (int)>  fn){
    for(int num:number){
        if(fn(num)){
            std::cout<<num<<"\n";
        }
    }
} 

void Square(int number){
    std::cout<<number* number;
}

bool Mod7(int number)
{
    return number%7==0;
}

bool DivBy7_11(int number){
    return number % 7 == 0 && number % 11 == 0;
}

bool IsPrime(int number){
    if(number == 0 || number == 1){
        return false;
    }
    if(number<0){
        throw std::runtime_error("negative number cannot be prime or not.");
    }
    for(int counter=2;counter<number/2;counter++){
        if(number%counter==0){
            return false;
        }
    }
    return true;
}

int TakeInput(){
    int choice;
    std::cout<<"enter 1 for divby7_11. enter 2 for isprime, enter 3 for mod7.";
    std::cin>>choice;
    return choice;
}

int main(){
/*     Adaptor(10, &Square);
    Adaptor(10,
    [](int number) -> void //or (int number)
    {
        std::cout<<number*number;
    }
    );
    std::vector<int>data={1,2,3,4,5};
    std::cout<<std::count_if(
        data.begin(),
        data.end(),
        [](int number) {return number%5==0;}
    ); */

    std::vector<  std::function<bool(int)>  > fns{
        DivBy7_11,
        IsPrime,
        Mod7
    };

    int choice = TakeInput();
    if(choice == -1){

    } 
    else{
        Adaptor(std::vector<int>{1,2,3,4,5},fns[choice-1]);
    }

}
