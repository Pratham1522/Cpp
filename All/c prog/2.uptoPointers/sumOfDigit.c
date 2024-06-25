/*If a five-digit number is input through the keyboard, write a
program to calculate the sum of its digits. (Hint: Use the modulus
operator ‘%’)
*/
#include<stdio.h>
int main(){
    int num,rem,sum=0;
    printf("Enter a five digit number : ");
    scanf("%d",&num);
    while(num>0){
        rem=num%10;
        sum+=rem;
        num/=10;
    }
    printf("Sum of digits are : %d\n",sum);
    return 0;
}