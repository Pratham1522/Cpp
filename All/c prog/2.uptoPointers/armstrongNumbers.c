/*Write a program to print out all Armstrong numbers between 1 and
500. If sum of cubes of each digit of the number is equal to the
number itself, then the number is called an Armstrong number. For
example, 153 = ( 1 * 1 * 1 ) + ( 5 * 5 * 5 ) + ( 3 * 3 * 3 ).
*/
#include<stdio.h>
int main(){
    int a,b,c;
    printf("Armstrong numbers are : ");
    for(int i=1;i<500;i++){  //let i=485
        a=i%10; //a=ones digit =5
        b=i%100; //b = 85
        c=(b-a)/10; // c=tenth digit 8
        b=i/100; //hundred th digit 4
        
        if(a*a*a + b*b*b +c*c*c ==i){
            printf( "%d ", i);
        }
    }
}