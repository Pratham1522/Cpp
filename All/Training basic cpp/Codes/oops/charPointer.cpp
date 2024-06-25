#include<iostream>

void sum(int a,int b=0,int c=0)
{
    int add=a+b;
    std::cout<<"\n addition = "<<add;
}


int main()
{
    char *s=new char[20];
    std::cout<<"enter string ";
    std::cin>>s;
    std::cout<<"String is "<<s;

    delete [] s;

    sum(10,20,30);
    sum(10,30);
    sum(10);
}