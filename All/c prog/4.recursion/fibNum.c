/* Generate first 25 terms of a Fibonacci sequence using recursion */ 
#include<stdio.h>
void genFib(int ,int ,int);
int main(){
    int a=0,b=1;
    printf("Fib sequence is : 0 1 ");
    genFib(0,1,1);
}
void genFib(int f,int s,int count){
    if(count<25){
        int temp=f;
        f=s;
        s=s+temp;
        printf("%d ",s);
        genFib(f,s,++count);
    }
}