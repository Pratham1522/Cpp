#include<stdio.h>
#include<math.h>

int playwidnum(long n){
    long prod=1;
    long temp=n;
    int res;
    long max=pow(2,8*sizeof(int));
    while(temp>0){
        int rem=temp%10;
        // printf("rem is : %d,prod is : %ld \n",res,prod);
        prod*=rem;
        temp/=10;
    }
    // printf("%ld \n",prod);
    if(prod>max){
        return -1;
    }
    if(prod%2==0){
        int lar=0;
        int temp=n;
        while(temp>0){
            int rem=temp%10;
            if(rem>lar){
                lar=rem;
            }
            temp/=10;
        } 
        res=lar*lar*lar;
    }
    else{
        int temp=n;
        res=0;
        while(temp>0){
            int rem=temp%10;
            res+=(rem*rem);
            temp/=10;
        }
    }
    return res;
}
int main(){
    printf("Enter a number : ");
    int res;
    long num;
    scanf("%ld",&num);
    res=playwidnum(num);
    printf("Output is : %d \n",res);

}

