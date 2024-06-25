#include "bill.h"
#include <cstring> 

void totalamount(bill p[])
{   
    int sum=0;
    for(int i=0;i<3;i++){
      sum=sum+p[i].getBillamount();
    }
    std::cout<<sum<<std::endl;
    std::cout<<std::endl;
}

int main()
{
    bill p[3];
    for(int i=0;i<3;i++){
         bill p[i];
         p[i].accept();
    }

    for(int i=0;i<3;i++){
         std::cout<<p[i];
    }

    std::cout<<"Total Billamount"<<std::endl;
    totalamount(p);
    
    std::cout<<"Enter name"<<std::endl;
    char ant[10];
    std::cin>>ant;
    std::cout<<std::endl;

    for(int i=0;i<3;i++){
        if(p[i].find(ant)){
            std::cout<<p[i];
            break;
        }
    }

}