#include<iostream>
using namespace std;

class base{
    public:
    void h(){
        cout<<"base h called \n";
    }
    virtual void f(){
        cout<<"base f called \n";
    }
    virtual void g(){
        cout<<"base g called \n";
    }
};
class der1:public base{
    public:
    void h(){
        cout<<"der1 h called \n";
    }
    virtual void f(){
        cout<<"der1 f called \n";
    }
};
class der2: public der1{
    public :
    virtual void x(){
        cout<<"der2 x called \n";
    }
    virtual void g(){
        cout<<"der2 g called \n";
    }
    virtual void f(){
        cout<<"der2 f called \n";
    }
};

int main(){
    // base *p;
    // der2 d2;
    // p=&d2;
    // p->h(); 
    // p->f();
    // p->g();   //der2 g
    // // p->x();

    // der1 *d;
    // der2 d2;
    // d=&d2;
    // d->h();
    // d->f();
    // d->g();
    // // d->x();

    base *b;
    der1(d1);
    b=(base*) &d1;
    b->h();
    b->f();
    b->g();
}
