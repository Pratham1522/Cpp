#include<iostream>
using namespace std;

int main(){
    int A[5]={10};      //declaration of an array. 
    // A[0] will have value 10 all other elements will have value 0
    //can create array of any type char,int,float,etc.
    //if we mention size as 5 and give elements more than 5 then compile time error.
    for(int i=0;i<5;i++){
        cout<<"A of i is "<<A[i]<<"\n";    //if we dont initialise the array ,then elements take garbage value
        cout<<"Address "<<&A[i]<<"\n";     // Address differ by 4 for integer
    }

    cout<<"\nA[4] is same as *(A+4) ="<<*(A+4)<<"\n\n";   //*(A+4) is same as A[4]
    
    int B[6]={1,2,3,4};  
    for(int x:B){         //for each loop ,useful for arrays ,readed as foreach x in B ,benefit : no explicit size needed.
        cout<<"B element "<<x<<"\n";       //iteration depends on size of array,not no. of elements in array.
    }
    //can also write for(auto x:B){} // dont need to mention type.
    

    cout<<"\n";              //size 4 array will be created.
    char C[]={'A',66,'C',68};
    for(int x:C)            //foreach loop can typecast values if needed. eg.float to int or char to int.
        cout<<x<<"\n";      

    int D[]={8,6,3,9,7,4};
    for(int &x:D){          //if you want to reflect changes in array ,give reference
        x++;
        cout<<x<<"\n";
    }     

}