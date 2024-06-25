#include<iostream>
using namespace std;
class CDummy{
    public:
    int isitme(CDummy& param);
    CDummy(){
        cout<<"Constructor called \n";
    }

    ~CDummy(){
        cout<<"Destructor called \n";
    }
};
int CDummy::isitme(CDummy& param){
    if(&param == this)
        return true;
    else
        return false;    
}
int main(){
    CDummy a;
    CDummy *b=&a;
    if(b->isitme(a)){
        cout<<"execute";
    }else{
        cout<<"not execute";
    }
    return 0;
}