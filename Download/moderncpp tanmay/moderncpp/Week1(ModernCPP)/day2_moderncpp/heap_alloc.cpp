#include<cstdlib>
#include<iostream>

int main(){
    int *ptr = (int*)malloc(sizeof(int));
    int *carr = (int*)malloc(3*sizeof(int));
    carr[0]='c';

    int *cpparr = new int[3];
    //decide what u want to store and calc the size you want
    malloc(20);
    malloc(sizeof(float) * 5);
    new float[5];
}