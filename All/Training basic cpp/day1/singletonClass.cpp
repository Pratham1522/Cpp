#include <iostream>
static int count;
class singleton{    
    private:
        singleton(){
            std::cout<<"object "<< count+1 <<" created. \n";
        }
    public:
        static singleton createObject(){
            if(count>0){
                std::cout<<"Only one object is permitted \n";
                exit(0);
            }else{
                singleton s=singleton();
                count++;
                return s;
            }
            exit(0);
        }    
};
//overloading : order,type,num of args.
//const objects cannnot acces non const members
//const objects dont have a constructor by default ,write it explicitily.

int main(){
    singleton s = singleton::createObject();
    singleton p = singleton::createObject();
    return 0;
}    

//heap memory is not contigious ,stack memory is contigious -faster access
//new calls contructor,but malloc dont
//heap auto deletion not possible,stack have(once scope is gone)
//deep down reference is a constant pointer which dereference automatically.
