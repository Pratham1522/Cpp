/*If the marks obtained by a student in five different subjects are
input through the keyboard, write a program to find out the
aggregate marks and percentage marks obtained by the student.
Assume that the maximum marks that can be obtained by a student
in each subject is 100.
*/
#include<stdio.h>
int main(){
    float m1,m2,m3,m4,m5,agg,per;
    printf("Enter Marks in Subject 1 : ");
    scanf("%f",&m1);
    printf("\n Enter Marks in Subject 2 : ");
    scanf("%f",&m2);
    printf("\n Enter Marks in Subject 3 : ");
    scanf("%f",&m3);
    printf("\n Enter Marks in Subject 4 : ");
    scanf("%f",&m4);
    printf("\n Enter Marks in Subject 5 : ");
    scanf("%f",&m5);
    //Calculating aggregate marks
    agg=m1+m2+m3+m4+m5;
    per=agg/5;
    printf("\n Aggregate Marks = %.2f ",agg);
    printf("\n Percentage Marks = %.2f %%\n",per);
    return 0;
}