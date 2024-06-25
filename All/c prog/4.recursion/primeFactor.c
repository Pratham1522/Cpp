/* Find Prime Factors of a number recursively */

#include<stdio.h>
void factorise(int,int);
int main(){
    int num,i;
    printf("Enter a number : ");
    scanf("%d",&num);
    printf("Prime factors are : ");
    factorise(num,2);
    return 0;
}
void factorise(int n,int i){
    if(i<=n){
        if(n%i==0){
            printf("%d ",i);
            n/=i;
        }else{
            i++;
        }
        factorise(n,i);
    }
}