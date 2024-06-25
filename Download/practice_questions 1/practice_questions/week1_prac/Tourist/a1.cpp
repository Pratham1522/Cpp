#include<iostream>

class a1
{
private:
    int s;
public:
    a1(int num):s{num} {std::cout<<s;}
    ~a1() {}
};

int main(){
    a1 a(4.2);

}