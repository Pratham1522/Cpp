/*
Any character is entered through the keyboard, write a program to
determine whether the character entered is a capital letter, a small
case letter, a digit or a special symbol.
The following table shows the range of ASCII values for various characters:
Characters ASCII Values 
A – Z 65 – 90 
a – z 97 – 122 
0 – 9 48 – 57 
special symbols 0 - 47, 58 - 64, 91 - 96, 123 - 127
*/

#include<stdio.h>
int main(){
    char ch;
    printf("Enter char to verify : ");
    scanf("%c", &ch);
    if(ch>=65 && ch<=90)
        printf("%c is Capial.",ch);
    else if(ch>=97 && ch<=122)
        printf("%c is Small.",ch);
    else if(ch>=48 && ch<=57)
        printf("%c is Number.",ch);
    else if(ch>=0 && ch<=127)
        printf("%c is Special Symbol.",ch);
    return 0;
}