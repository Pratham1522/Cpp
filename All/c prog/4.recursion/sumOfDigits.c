/* Calculate sum of digits of a five-digit number using recursion */

#include<stdio.h>
int sumD(int);
int main(){
    int num,sum;
    printf("Enter 5 digit number : ");
    scanf("%d",&num);
    sum=sumD(num);
    printf("Sum of digits : %d\n",sum);
    return 0;
}
int sumD(int n){
    int s,rem;
    if(n>0){
        rem=n%10;
        s=rem+sumD(n/10);
    }else{
        return 0;
    }
    return s;
}