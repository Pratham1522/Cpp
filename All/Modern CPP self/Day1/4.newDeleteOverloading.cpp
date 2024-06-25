#include<iostream>
using std::cout;
using std::endl;
#define line(msg) cout<<"---------------"#msg"------------------\n";

class Cat{
    public:
    Cat(){
        cout<<"CAT Default\n";
        throw 100;
    }
    Cat(const Cat&)
    {
        cout<<"CAT Copy C-tor \n";
    }
    Cat& operator=(const Cat&)             
    {
        cout<<"CAT Assign Operator \n";
        return *this;
    }
    static void* operator new(size_t size){
        cout<<"CAT operator NEW\n";
        return malloc(100);
    }
    static void operator delete (void *pv){
        cout<<"CAT operator DELETE \n";
        free(pv);
    }
    ~Cat(){
        cout<<"CAT Destructor\n";
    }

};
int main(){
    line(welcome);
    
    Cat* cat = NULL;
    try{
        cat = new Cat(); 
        //temp pointer ,try(constructor ),catch(delete) ,cat=temp
        //if init fails then call delete operator immediatedly
    }
    catch(int exp){
        cout<<"exp : "<<exp<<"\n";
    }
    if(cat!=NULL){
        cout<<"Orange\n";
        delete cat;
    }else{
        cout<<"Apple\n";
    }

    line(come_back_again);
    return 0;
}
//new and delete always overload in pairs.

 /*
    cat=new Cat() ; creates temp pointer, exception handling(constructor call), return address of obj

    cat *temp=operator new(1); //temp pointer
    try{
        temp->Cat::Cat(); //constructor call
    } catch(...)
    {
        operator delete(temp);
        throw;
    }
    cat=temp;  //return  address after complete process execution
*/

/*
    delete cat; call destructor n delete operator(to delocate the memory).

    cat->Cat::~Cat();
    Cat::operator delete(cat);
*/

