#include<iostream>
#include "Candidate.h"
#include "Test1.h"
#include "Test2.h"


int main(){
    Candidate obj[3];
    for(int i=0;i<3;i++){
        obj[i].accept();
        std::cout<<obj[i];
        Test1 t1;
        Test2 t2;
        t1.accept();
        t2.accept();
        if((t1.marksSecured()>=70 && t2.marksSecured()>=150) || (t1.marksSecured()>=60 && t2.marksSecured()>=160)){
            std::cout<<"You are selected.\n";
        }
        else{
            std::cout<<"You are not selected.\n";
        }
    }
}
