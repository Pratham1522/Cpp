/*Write a program to receive Cartesian co-ordinates (x, y) of a point
and convert them into polar co-ordinates (r, ).
Hint: r = sqrt ( x2 + y2) and tan-1( y / x )
*/
#include<stdio.h>
#include<math.h>

int main(){
    float x,y,r,a;
    printf("Enter the value of x & y: ");
    scanf("%f %f",&x,&y);
    r=sqrt(x*x+y*y);
    a=atan2(y,x);
    a=a*180/3.14;
    printf("Polar coordinates are r= %.2f and angle= %.2f degrees.\n",r,a);
    return 0;
}

//use -lm to link libm file while compiling.