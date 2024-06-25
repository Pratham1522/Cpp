/*If a five-digit number is input through the keyboard, write a
program to reverse the number.
*/
#include<stdio.h>
int main(){
    int num,rev=0,rem;
    printf("Enter a Number to reverse : ");
    scanf("%d",&num);
    while(num>0){
        rem=num%10;
        rev=rev*10+rem;
        num/=10;
    }
    printf("Reverse number is : %d\n",rev);
    return 0;
}