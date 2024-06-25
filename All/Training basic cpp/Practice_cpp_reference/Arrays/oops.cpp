#include<iostream>
using namespace std;

class rect{
    int l,b;
    public:
    rect(int a=0,int c=0){
        l=a;b=c;
    }
    int area();
};
int rect::area(){
    l=10;
    return l*b;
}


int main(){
    rect r1(4,5);
    cout<<r1.area()<<endl;
}
// Abstraction : hiding internal implementation or working.
// Encapsulation : wrapping up of data and functions together,to avoid data mishandling. private data,public functions.
// Encapsulation: bundling the data and methods that operate on the data within a single unit.
// Inheritance : reusing of prewritten code , inherit from class.
// polymorphism : same name ,different works.

// class : blueprint for objects.
// object : instance of objects.

//when we declare obj ,they will occupy memory in stack
// size of class depends on no. of var,and their size.
// functions will not occupy any memory but will be there
// in code section ,class defination is not present but their functions will be present.

//pointer to an object
/*
Rectangle *r1,r2;   //object created in stack
r1=&r2;
r1->length=10;       //use of arrow operator : pointer
r2.breadth=5;        //use of dot operator : object
*/

//object in heap
/*
Rectangle *p=new Rectangle();
p->length=14;
*/

//setters functions must validate data before assigning .
//getter function can be used to get value of private variable.

//parametrised no arg constructor can be used as default constructor.
//can use setters in parameterised constructor to validate data.
//copy constructor 
/*
p=new int[a];
for loop to copy values.
*/

//scope resolution very important 
/*
when you write function directly inside class ,on exeution it just replaces at place of function call
but when u write function outside, it just define it somewhere and call it whenever needed.
inline function : expanded in same line as they are called.
to make them explicitily inline (for outside functions) use keyword inline.
*/

//struct in c has only data members no functions
// in c++ struct has data members as well as member functions.
//in c++ struct and class r similar,just struct dont have access specifiers.