#include<iostream>

class inherit
{
private:
    int x;
public:
    inherit() {std::cout<<"parent const\n";}
    ~inherit() {std::cout<<"parent dest\n";}
    virtual void solve(){std::cout<<"solve base\n";}

};

class child:public inherit{
    public:
    child(){
        std::cout<<"child\n";
    }
    void solve() override{std::cout<<"child func\n";}
    ~child(){
        std::cout<<"cdest\n";
    }
};

int main(){
    inherit *c = new child;
    c->solve();
    delete c;
}


/* 
default
delete
CPP OOPS
enum class
nullptr
override keyword
new 
const
lval rval
final
move semantic
 */