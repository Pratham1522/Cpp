// Online C compiler to run C program online
#include <stdio.h>

int main() {
    // Write C code here
    
    float s1,s2,s3,sums,ls;
    printf("Enter 3 sides of Triangle : ");
    scanf("%f %f %f" ,&s1,&s2,&s3);
    
    
    if(s1!=s2 && s1!=s3 && s2!=s3)
        printf("scelence Triangle");
    else if(s1==s2 && s1==s3)
        printf("Equilateral Triangle");
    else if((s1==s2 && s1!=s3) || (s1==s3 && s1!=s2) || (s3==s2 && s2!=s1))
        printf("Isosceles Triangle");
        
    int a,b,c;
    a=s1*s1==s2*s2 +s3*s3;
    b=s2*s2==s3*s3+s1*s1;
    c=s3*s3==s1*s1+s2*s2;
    if(a||b||c)
        printf("Right Angle Triangle");
        
    // if(s1>s2){
    //     if(s1>s3){
    //         ls=s1;
    //         sums=s2+s3;
    //     }else{
    //         ls=s3;
    //         sums=s1+s2;
    //     }
    // }else{
    //     if(s2>s3){
    //         ls=s2;
    //         sums=s1+s3;
    //     }else{
    //         ls=s3;
    //         sums=s1+s2;
    //     }
    // }
    // if(ls<sums)
    //     printf("Valid Triangle");
    // else
    //     printf("Invalid Triangle");
    
    // printf("Entered sides are : %f ,%f ,%f",ls,sums,s3);
    return 0;
}

