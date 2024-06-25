#include<stdio.h>
int main()
{
    int x=200;
    int* y=&x;
    int** z=&y;
    char* a;
    float* b;
    printf("Sizeof Int pointer :%ld",sizeof(y));   //all pointer have same size.
    printf("\nSizeof Double pointer :%ld",sizeof(z));
    printf("\nSizeof Char pointer :%ld",sizeof(a));
    printf("\nSizeof float pointer :%ld",sizeof(b));
    printf("\nValue of x :%d",x);
    printf("\nValue of x :%d",*y);
    printf("\nValue of x :%d",**z);
    printf("\nAddress of x :%p",&x);
    printf("\nAddress of x :%p",y);
    printf("\nAddress of x :%p",*z);
    printf("\nAddress of y :%p",&y);
    printf("\nAddress of y :%p",z);
    printf("\nAddress of z :%p",&z);
    printf("\n");
    return 0;
}
//int* j ; int * j ; int *j ;  are same