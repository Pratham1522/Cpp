#include<iostream>

class Ex{
    private:
    int a;

    public:
    Ex(int var){
        a=var;
        std::cout<<__PRETTY_FUNCTION__<<"Constructor Called \n";
    }
    Ex(const Ex &other){
        a=other.a;
        std::cout<<"Copy Constructor Called \n";
    }
    ~Ex(){
        std::cout<<__PRETTY_FUNCTION__<<"Destructor Called \n";
    }

};

int main(){
    // int a=10;
    // int &b=a;
    // int c=30;
    // b=c;
    // std::cout<<"a "<<a <<"\n";
    // std::cout<<"b "<<b <<"\n";
    // std::cout<<"c "<<c <<"\n";

    Ex obj1 = Ex(23);
    Ex obj2 = Ex(obj1);
    return 0;

    //shallow and deep copy is concept of dynamic memory allocation.
    /*
    shallow copy
    int *p=new int(100);
    int *q=p;

    deep copy 
    int *p=new int(100);
    int *q=new int
    */

   //copy constructor perform in 3 ways.
   /*
    //    &: avoid stack overflow, again n again call
   */

//   const object need a explicit constructor to initilaise values ,default constructor will not work for const object.
//   or use const A obj{};
// write short constructor(initialer list) as A():i(10); in public 
// object creation 2 steps: space allocation +constructor called


//allocation using new and dealloc using free :  undefined behavior +memory leak.
// when new fails to allocate memory : bad alloc.
//alloction using malloc and delloc using delete : undefined behavior
}

