#include<stdio.h>
int romanConvert(int,int,char);
int main(){
    int yr;
    printf("\n Enter the year : ");
    scanf("%d",&yr);
    yr=romanConvert(yr,1000,'m');
    yr=romanConvert(yr,500,'d');
    yr=romanConvert(yr,100,'c');
    yr=romanConvert(yr,50,'l');
    yr=romanConvert(yr,10,'x');
    yr=romanConvert(yr,5,'v');
    yr=romanConvert(yr,1,'i');
}
int romanConvert(int yr,int r,char c){
    int i,j;
    j=yr/r;
    for(int i=1;i<=j;i++){
        printf("%c",c);
    }
    return yr%r;
}
