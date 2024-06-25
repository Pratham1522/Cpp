#include<stdio.h>
void swapN(int*,int*);
int main()
{
    int a=5,b=10;
    swapN(&a,&b);
    printf("a=%d b=%d\n",a,b);
    return 0;
}
void swapN(int *p,int *q)
{
    int temp=*p;
    *p=*q;
    *q=temp;
}