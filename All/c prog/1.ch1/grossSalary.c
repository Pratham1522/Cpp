/*Ramesh’s basic salary is input through the keyboard. His dearness
allowance is 40% of basic salary, and house rent allowance is 20% of
basic salary. Write a program to calculate his gross salary.*/

#include<stdio.h>
int main()
{
    float salary,da,hra;
    printf("Enter Ramesh's Basic Salary: ");
    scanf("%f", &salary);
    da=0.4*salary;
    hra=0.2*salary;

    float finalsalary=hra+da+salary;
    printf("Gross Salary = %.2f\n",finalsalary);
    return 0;
}