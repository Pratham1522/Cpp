#include<iostream>
using namespace std;
//structure are blueprint or templates and  dont occupy space in memory ,0 bytes,but structure variable will occupy memory.
//structure variables are specific instances enjoying differnet data.
/*
struct person{
    char n[20];int a;float h;
}
person p1={"ram",18,5.6}
person p2={"shyam",28,4.3}

printf("%s %d %f",p1.n,p1,a,p1.h);
person* p;
p=&p1;
printf("%s %d %f",p->n,p->a,p_>h);

//2 ways to access memory loc ,name and address.

//Top : pointer of stack

//types of statements:sequential,decision,repetation,case based

//for loop :entry control + where num of iterations are known in advance.
//while loop:entry contro + where num of iterations arent known in advance.
// do-while loop: exit control loop.

//object : instance of class.
//class :blueprint of real world entity
//encapsulation : wrapping up of properties and procedures.
//procedural sol: focuses on procedures and no importance to data.

// s1.top=-1, oo keeps data and proc together, use private to validate data and public access specifier to give function access.

// in c structure is collection of data only, in c++ structure is collection of data and fucntions 

//cout : characater output, << insertion operator, >> extraction operator.

//struct access specifier by default public, class is by default public.
if var in class are public we dont get any oops benefits.
eg. public int i;float j;
so var must be private(data hiding) and you need to write function to get and set data,getter - get the members, setters -set the data

we can also hide functions in class
this keyword/pointer(address of object calling the function) maintains reference between instance and variables. assigned by default by compiler ,only write explicitity when actual amd formal parameter have same name.
this is a constant pointer. as local variable gets the priority.

cpp protects againts accident but not fruad
we can modify private variables of class outside the class using pointers.

avoid using namespace std to avoid gloo=bal function name conflict

*/

// class Ex;//forword declaration.
// void printalldata(Ex);

// class ex{
//     private :
//         int i;float a;
//     public:
//         void setdata(int i,float a){
//             this->i=i;
//             this->a=a;
//         }    
//         void printdata(){
//             std::cout<<i<<" "<<a<<"\n";
//         }
// };


// int main() {
//     ex e1,e2;
//     e1.setdata(1,1.5);
//     e2.setdata(2,3.7);

//     e1.printdata();
//     e2.printdata();

//     int a=7,b=4;
//     std::cout<<a+b<<"\n";
//     std::cout << "Hello World \n";
//     return 0;
// }


// class stack{
//     private:
//     int top;
//     int a[10];

//     public:
//     stack(){
//         top=0;
//     }
//     void push(int x){
//         a[top=x]; top++;
//     }
// };
// int main(){
//     stack s1;
//     s1.push(10);
//     stack s2;
//     s2.push(50);
// }

class ex{
    private:
    int i;float j;

    public :
    ex(int ii=0,float jj=0.0){
        i=ii;j=jj;
    }
    void set(int x,float y){
        i=x;j=y;
    }
    void print(){
        cout<<i<<" "<<j<<"\n";
    }
    void add(){
        cout<<this<<" from class \n";
    }
};
int  main(){
    ex e1(10,20.8);
    ex e2;
    ex e3(15);
    e3=ex(19,2.9);   //explicit constructor call.
    ex e4=5; // {3,5.6} also works
    cout<<&e4<<" from main \n";
    e4.add();
    e1.print();
    e2.print();
    e3.print();
    e4.print();
    return 0;
}
// in for loop always use ++i instead of i++.


