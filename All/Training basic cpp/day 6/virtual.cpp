#include<iostream>
using namespace std;

class mysmartclass{
    int* x;

    public:
    mysmartclass(int* y){
        x=y;
    }
    ~mysmartclass(){
        delete x;
    }
    int& operator * () {
        return *x;
    }
    // int* operator ->(){
    //     return &x;
    // }

};

int main(){
    mysmartclass obj(new int);
    *obj=100;   
    //obj->300;
    cout<<*obj;

}

//virtual destructor
//virtual constructor

