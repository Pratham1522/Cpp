#include<stdio.h>
void areaPeri(int,float*,float*);
int main()
{
    int radius;
    float area,peri;
    printf("Enter the radius : ");
    scanf("%d",&radius);
    areaPeri(radius,&area,&peri);
    printf("\nArea of Circle : %.2f",area);
    printf("\nPerimeter of Circle : %.2f\n",peri);
    return 0;
}
void areaPeri(int r,float *a,float *p)
{
    *a=3.14*r*r;
    *p=2*3.14*r;
}