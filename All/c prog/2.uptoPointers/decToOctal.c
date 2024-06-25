/*Write a program to receive an integer and find its octal equivalent.
(i) (Hint: To obtain octal equivalent of an integer, divide it continuously
by 8 till dividend doesn’t become zero, then write the remainders
obtained in reverse direction.)
*/

#include<stdio.h>
int main(){
    int dec,oct=0,num,rem,temp=0;
    printf("Enter a number to convert : ");
    scanf("%d",&dec);
    num=dec;
    while(num>0){
        rem = num%8;
        oct = rem*10+oct;
        num /= 8;
    }
    num=oct;
    while(num>0){
        rem=num%10;
        temp=temp*10+rem;
        num/=10;
    }
    printf("\nOctal Equivalent is %d",temp);
    return 0;
}