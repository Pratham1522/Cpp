// resusability :
// compositon : class out of scope ,all object destroyed. (milk in glass)
// aggregation : class destroyed,then also obj can be used in other class,(fish stone : dynamic memory)
// Association : compostion + aggreation.

#include<iostream>
using namespace std;

class stringlist{
    int capacity;
    string* slist;
    int size;

    public :
    stringlist(int c=5){
        size=0;
        capacity=c;
        slist=new string[capacity];
    }
    
    explicit stringlist(const stringlist &obj){  //copy constructor
        size=obj.size;
        capacity=obj.capacity;
        for(int i=0;i<size;i++){
            slist[i]=obj.slist[i];
        }
    }
    stringlist& operator = (stringlist &obj) {
        size=obj.size;
        capacity=obj.capacity;
        for(int i=0;i<size;i++){
            slist[i]=obj.slist[i];
        }
        return *this;
    }

    
    ~stringlist(){      //destructor of dynamic memory
        delete []slist;
        slist=nullptr;
    }
    void add(string str){
        if(size<capacity){
            slist[size]=str;
            size++;
        }
        else{
            capacity=2*capacity;
            string* slist1=new string[capacity];
            for(int i=0;i<size;i++){
                slist1[i]=slist[i];
            }
            delete []slist;
            slist=slist1;
            slist1=nullptr;
            slist[size]=str;
            size++;
        }
    }
    void display(){
        cout<<"size is "<<size<<"\n";
        cout<<"capacity is "<<capacity<<"\n";
        cout<<"list is : {";
        for(int i=0;i<size;i++){
            cout<<slist[i]<<" ,";
        }
        cout<<"} \n";
    }
    void operator () (void){
        cout<<"size is "<<size<<"\n";
        cout<<"capacity is "<<capacity<<"\n";
        cout<<"list is : {";
        for(int i=0;i<size;i++){
            cout<<slist[i]<<" ,";
        }
        cout<<"} \n";
    }
    //pop operator.
};
int main(){
    stringlist l(3);
    l.add("name1");
    l.add("name2");
    l.add("name3");
    l.add("name4");
    stringlist l1; //assignment operator overloading
    l1=l;
    l1.display();
    // l.display();
    // l();   //functor   
    return 0;
}

//g++ run automation
/*
default:
    g++ command
clean:
rm output_file_name out;

//makefile,cmake
*/
//use doxygen for new project.
//library creation : static .a or .so (shared object)

// obj u;
//u++ is implemented as u.operator++()