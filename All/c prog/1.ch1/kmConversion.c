/*The distance between two cities (in km.) is input through the
keyboard. Write a program to convert and print this distance in
meters, feet, inches and centimeters.*/

#include<stdio.h>
int main(){
    float km,m,f,in,cm;
    printf("Enter the distance in km : ");
    scanf("%f",&km);
    m=1000*km;
    cm=100*m;
    in=cm/2.54;
    f=m*3.28;
    printf("\nDistance in meters = %.2f",m);
    printf("\nDistance in feet = %.2f",f);
    printf("\nDistance in inch = %.2f",in);
    printf("\nDistance in cm = %.2f",cm);
    return 0;

}
