/*Temperature of a city in Fahrenheit degrees is input through the
keyboard. Write a program to convert this temperature into
Centigrade degrees.
*/
#include<stdio.h>
int main(){
    float fah,deg;
    printf("Enter Temperature in Fahrenheit: ");
    scanf("%f",&fah);
    deg = (fah-32)*5/9;
    printf("%0.2f Degrees Celsius\n",deg);
    return 0;
}