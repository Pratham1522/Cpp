#include<iostream>
using namespace std;

class A{
    int id;

    public:
    static int count;
    A(){
        count++;
        id=count;
        cout<<"constructor called"<<id<<endl;
    }
    ~A(){
        cout<<"destructor called"<<id<<endl;
    }
};
int A::count=0;
int main(){
    // cout<<"Memory of"<<sizeof(A);
    A a[5];
    // delete []a;
    cout<<"static "<< A::count<<"\n";
    return 0;
}
// static variables are global var, they can be private in class and not accessible outside.
// they are stored in class memory not in object memory and is shared between all the objects.
// static var can be dec inside class but must be inialised outside class using class resolution operator.
// static vr lifetime until program ends, scope within blocks.