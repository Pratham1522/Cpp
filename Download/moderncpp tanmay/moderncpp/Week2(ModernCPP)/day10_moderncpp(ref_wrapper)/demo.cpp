/* #include<iostream>
#include<functional>

class Magic{
    private:

    public:
        int operator()(int number){
            return number*number;
        }
};

int main(){
    Magic mike;
    std::cout<<mike(10);
    std::cout<< Magic{}(10);

    auto f1 = [](int number){return number*number;};
    // or std::function<int (int number)> f1 = [](int number){return number*number;};
    //here f1 is same as function call operator i.e. Mike -->().
    std::cout<<f1(10);
}

//lambdas always creates a class in the background and makes a function. This is done by the compiler
 */