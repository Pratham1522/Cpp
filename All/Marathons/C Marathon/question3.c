#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void groupAnalyzer(char* s,int n,int gl){
    char res[n][gl];
    int i=0;
    while(i<n-gl+1){
        char sstr[gl];
        int index=0;
        for(int j=i;j<i+gl;j++){
            sstr[index]=s[j];
            index++;
        }
        printf("substr %d is %s \n",i,sstr);
        // res[i][0]=&sstr[0];
        i++;
    }
    // for(int i=0;i<4;i++){
    //     printf("%s \n",res[i][0]);
    // }

}

int main(){

    // char* s;
    // printf("Enter Sring : ");
    // scanf("%s",s);
    // int n=strlen(s);

    // int sublen;
    // printf("Enter the length of groups : ");
    // scanf("%d",&sublen);a
    // groupAnalyzer(s,n,sublen);

    char s[9]="abcdabcde";
     groupAnalyzer(s,9,2);
    // char arr1[3][3];
    // for(int i=0;i<3;i++){
    //     for(int j=0;j<3;j++){
    //         arr1[i][j]="abc"[i];
    //     }
    // }
    // for(int i=0;i<3;i++){
    //     for(int j=0;j<3;j++){
    //         printf("%d ",arr1[i][j]);
    //     }
    //     printf("\n");
    // }

}