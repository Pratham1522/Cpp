/*program to find average marks obtained by a class of 30
students in a test.*/

#include<stdio.h>
int main(){
    int marks[5],sum=0;
    for(int i=0;i<5;i++){
        printf("Enter marks of Student : %d ",i);
        scanf("%d",&marks[i]);
        sum+=marks[i];
    }
    printf("Avg marks of Students is %d\n",sum/5);
    return 0;
}