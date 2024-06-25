#include<stdio.h>
void display1(int *);
void display2(int[]);
int main(){
    int num[]={2,3,4,5,6};
    display2(&num[0]);
    display1(&num[0]);
}
void display1(int *arr){
    printf("Array : ");
    for(int i=0;i<5;i++){
        printf("%d ",*arr++);

    }
}
void display2(int arr[]){
    printf("\nArray : ");
    for(int i=0;i<5;i++){
        printf("%d ",arr[i]);
    }
}
