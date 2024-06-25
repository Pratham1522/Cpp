#include<memory>
#include<iostream>
/* 
if a resource should only have 1 owner in ur s/w at any point and no option of replicating/sharing
ownership is expected, use std::unique_ptr

eg: there is 8 bytes of memory starting from 0x100H

Main func : ptr1 [0x100H]
Magic func : ptr2 [0x100H]
 */

void Magic(std::unique_ptr<int[]>& pt1){

}

int main(){
    /* 
    i want to make sure that a raw pointer returned from this allocation is not accessible frmo next statement
    onwards
    since this is allocation for integer array, unique ptr needs to be aware about it, hence new int[]
    since we dnot have to forward any parameters to any constructor, we can skip make_unique.
     */
    std::unique_ptr<int[]> ptr1 {new int[2]}; //8 bytes
    Magic(ptr1);//pass by reference, since copy is not allowed
}
