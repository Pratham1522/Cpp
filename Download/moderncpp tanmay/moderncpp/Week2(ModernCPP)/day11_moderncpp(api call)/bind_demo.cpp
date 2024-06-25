#include<iostream>
#include<cstring>
#include<functional>

class Dummy{
    private:
        int _factor;
    public:
        Dummy(int factor): _factor(factor){}
        void Magic(int n1){
            std::cout<<_factor * n1<<"\n";
        }
};

int addition(int x,int y, int z){
    return ((x+y)-z);
}

void Adaptor(int n1, int n2,std::function<int(int,int)>fn){
    std::cout<<fn(n1,n2);
}

int main(){
    auto fn = std::bind(&addition,100,std::placeholders::_1, std::placeholders::_2);
    //std::cout<<fn(20,30,40);
    std::cout<<fn(2,3);
    //objective: hardcode fn from adaptor to addition function
    auto binded_adaptor = std::bind(&Adaptor, std::placeholders::_1,std::placeholders::_2,
    [](int n1,int n2){return n1/n2;});
    // binded_adaptor(10,30);
    // auto aslistrcpy = std::bind(&strcpy, std::placeholders::_1,std::placeholders::_2,[](std::string a, std::string b){
    //     strcpy(a,b);
    // }
    // std::string temp;
    // aslistrcpy(temp,"hello");
    // std::cout<<temp;
    //Dummy d1(5);
    //auto b = std::bind(&Dummy::Magic,&d1, 100);// d1[0x100H] -> Dummy::Magic(int n)
    //b();

    // auto f1 = [](int number){std::cout<<number+5;};
    // auto binded_f1 = std::bind(f1,6);
    // binded_f1();

}

/* 
    original strcpy  (destination, source)

    Tanmay wants to switch parameters strcpy(source, destination)
*/

/* 
    FOR LAMBDAS DO NOT USE AMPERCENT BCOZ LAMBDAS ARE 1 TIME FUNCTIONS 
    THEY DO NOT HOLD ANY MEMORY SO WE CANNOT GIVE ITS REFERENCE
*/
