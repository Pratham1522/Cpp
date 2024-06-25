#include<iostream>

int main(std::string a[]){

    int n1=10;
    float f1 = 1.3f;
/* integer n3 variable is assigned the value of float f1 which is converted
     to integer type by cast */
    int n3 = (int) f1; //c-style cast
    //c++ static cast performs action at compile time. if conversion fails it give compilation error
    //NOT DESIGNED FOR POLYMORPHISM RELATED SITUATION.

    int n4 = static_cast<int>(f1);
}