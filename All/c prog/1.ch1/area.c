/*The length and breadth of a rectangle and radius of a circle are
input through the keyboard. Write a program to calculate the area
and perimeter of the rectangle, and the area and circumference of
the circle.*/
#include<stdio.h>
int main(){
    float l,b,areac,arear,rad,cir,per;
    printf("Enter the length of Rectangle : ");
    scanf("%f",&l);
    printf("Enter the breadth of Rectangle : ");
    scanf("%f",&b);
    printf("Enter the radius of circle : ");
    scanf("%f",&rad);
    arear=l*b;
    areac=3.14*rad*rad;
    per=2*(l+b);
    cir=2*3.14*rad;
    printf("\nArea of rectangle : %.2f",arear);
    printf("\nPerimeter of rectangle : %.2f",per);
    printf("\nArea of circle : %.2f",areac);
    printf("\nCircumference of circle : %.2f\n",cir);
    return 0;
}
