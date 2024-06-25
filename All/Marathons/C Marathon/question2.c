#include<stdio.h>
#include<math.h>

int assign(int num){
    if(num==1 || num==2 || num==6 || num==10){
        return 3;
    }else if(num==4 || num==5 || num==9){
        return 4;
    }else if(num==3 || num==7 || num==8){
        return 5;
    }else if(num==11 || num==12){
        return 6;
    }else if(num==15 || num==16){
        return 7;
    }else if(num==13 || num==14 || num==18 || num==19){
        return 8;
    }else if(num==17){
        return 9;
    }
    return 0;
}
int assigntens(int num){
    if(num==4 ||num==5 || num==6 || num==9){
        return 5;
    }
    else if(num==2 || num==3 || num==8){
        return 6;
    }
    else if(num==7){
        return 7;
    }   
}
int countletter(int num){   //452
    int fcount=0;          //16
    if(num==0){
        return 4;
    }
    // int cletter=countnum(num);
    while(num>0){
        //printf("num:%d ,fcount: %d",num,fcount);
        if(num>100){
            int rem=num/100;
            fcount+=assign(rem);
            fcount+=7; //hundred
            num=num % 100;
        }else if(num>19){
            int rem=num/10;
            fcount+=assigntens(rem);
            num%=10;
            // printf(" %d \n",rem);
        }
        else{
            fcount+=assign(num);
            num=0;
        }
    }
    
    return fcount;
}
void iSort(int* arr,int n){
    for(int i=0;i<n-1;i++){
        int max=i;
        for(int j=i+1;j<n;j++){
            if(arr[max]<arr[j]){
                max=j;
            }
        }
        if(max!=i){
            int temp=arr[i];
            arr[i]=arr[max];
            arr[max]=temp;
        }
        
    }
    int count=0;
    for(int i=0;i<n-1;i++){  
        if(arr[i]==arr[i+1]){
            arr[i]=-1;
            count++;
        }        
    }
    int x=n-count;
    int newArr[x];
    for(int i=0,j=0;i<n;i++){
        if(arr[i]!=-1){
            newArr[j]=arr[i];
            j++;
        }
    }
    printf("Output is : {");
    for(int i=0;i<x;i++){
        printf("%d, ",newArr[i]);
    } 
    printf("} \n");
}
void sortArrDesc(int* arr,int n){
    int arr1[n-1];
    for(int i=1;i<n;i++){
        int res=abs(arr[i]-arr[i-1]);
        int cres=countletter(res);
        arr1[i-1]=cres;        
    }
    // for(int i=0;i<n-1;i++){
    //     printf("%d, ",arr1[i]);
    // } 
    // printf("\n");
    iSort(arr1,n-1) ;  
}

int main(){
    int num;
    printf("Enter number of elements : ");
    scanf("%d",&num);
    int arr[num];

    for(int i=0;i<num;i++){
        printf("Enter %d Element : ",i);
        scanf("%d",&arr[i]);
    }
    printf("Array is : {");
    for(int i=0;i<num;i++){
        printf("%d, ",arr[i]);
    }
    printf("} \n");

    // int arr[5]={124,457,5,15,7};
    sortArrDesc(arr,num);

    
}
