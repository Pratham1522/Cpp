#include<iostream>

class A{
    public:
        int number=1;
        std::string name;
        int solve(){
            return number;
        }
};

int main(){
    int a=4;
    int b=5;

    const int *ptr=&a; //ptr is a pointer to const integer
    //*ptr=10; will give error
    ptr=&b;

    int * const ptr2 = &a; //ptr2 is a const pointer to an integer
    *ptr2=100;
    //ptr2=&b; will give error

    const int * const ptr3 = &a; //ptr3 is a const pointer to a constant integer
    //*ptr3 = 100; will give error
    //ptr3 = &b; will give error

    const A obj();
    int x=A.solve();
    cout<<x

}