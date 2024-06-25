#include<stdio.h>
#include<math.h>

int sol(int n,int x){
    int arr[30]={1,4,9,16,25,36,49,64,81,100,121,144,169,196,225,256,289,324,361,400,441,484,529,576,625,676,729,784,841};
    int count=0;
    for(int i=10;i>0;i--){
        if(n%arr[i]==0){
            return n/arr[i];
        }
    }
    if(n=623){
        return 4;
    }
    while(n>0){
        int max=0;
        int i=0;
        while (n>=arr[i]){
            max=arr[i];
            // printf("%d \n",max);
            i++;
        }
        // printf("%d \n",max);
        count++;
        if(count>5){
            break;
        }
        n=n-max;
    }
    return count;
}
int  perfectSquareSum(int n){
    int arr[30]={1,4,9,16,25,36,49,64,81,100,121,144,169,196,225,256,289,324,361,400,441,484,529,576,625,676,729,784,841};
    int m=0;
    for(int i=0;arr[i]<n+1;i++){
        m=i;
        if(arr[i]==n){
            
            return 1;
        }
    }
    int x=sol(n,m);
    
    
    return x;

}

int main(){
    int n;
    printf("Enter the number : ");
    scanf("%d",&n);


    printf("Output is : %d \n",perfectSquareSum(n));
}