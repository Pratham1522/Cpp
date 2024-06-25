/*If lengths of three sides of a triangle are input through the
keyboard, write a program to find the area of the triangle.*/
// #include<stdio.h>
// #include<math.h>
// int main(){
//     double a,b,c,sp,area; //side lengths of the triangle
//     printf("Enter sides of Triangle : ");
//     scanf("%lf %lf %lf",&a,&b,&c);
    
//     sp=(a+b+c)/2;
//     area=sqrt(sp*(sp-a)*(sp-b)*(sp-c));
//     printf("Area of Triangle : %lf",area);
//     return 0;
// }
#include<stdio.h>
#include<math.h>

int main(){
    double a,b,c,sp,area; //side lengths of the triangle
    printf("Enter sides of Triangle : ");
    scanf("%lf %lf %lf",&a,&b,&c);
    
    sp=(a+b+c)/2;
    area=sqrt(sp*(sp-a)*(sp-b)*(sp-c));
    printf("Area of Triangle : %lf",area);
    return 0;
}

//use -lm to link libm  while compiling