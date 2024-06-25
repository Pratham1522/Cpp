#include<stdio.h>
int main(){
    // int arr[5]={1,2,3,4,5};
    // int size=sizeof(arr)/sizeof(arr[0]);
    // printf("%d",size);
    // return 0;

    // char name[25];
    // printf("Enter name : ");
    // scanf("%[^\n]s",name);
    // printf("name : %s",name);
    // return 0;

    char name[25];
    printf("Enter name : ");
    gets(name);
    puts("Hello! ");
    puts(name);
    return 0;
    
}