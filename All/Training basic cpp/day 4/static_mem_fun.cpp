#include<iostream>
using namespace std;

class Ex{
    int x;

    public:
    static int count;
    Ex(const int y=0){
        x=y;
        count++;
    }
    static void getCount(){
        cout<<"Number of objects : "<<count<<"\n"; // can only access other static members.
    }
};
int Ex::count;    // must be defined outside the class.
//initialised to 0 when first object of class is created if no explicit declaration.
// only one copy of data member is created and shared between all objects of class.
// its lifetime is entire program.
// static var maintains values common to entire class

int main(){
    Ex e1,e2;
    cout<<"count : "<<Ex::count;
    Ex::getCount();       //calling synthax
    return 0;
}