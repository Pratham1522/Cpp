#include<iostream>
using namespace std;

void print(int A[],int n=1){
    cout<<"Array is : { ";
    for(int i=0;i<n-1;i++)
        cout<<A[i]<<" ";
    cout<<A[n-1]<<"} \n" ;   
}
void arr1(){        //basic
    int A[5]={10};      //declaration of an array. 
    // A[0] will have value 10 all other elements will have value 0
    for(int i=0;i<5;i++){
        cout<<"A of "<<i <<" is "<<A[i];    
        cout<<"\t Address is "<<&A[i]<<"\n";     // Address differ by 4 for integer
    }
    //can create array of any type char,int,float,etc.
    //if we mention size as 5 and give elements more than 5 then compile time error.
    //if we dont initialise the array ,then elements take garbage value

    cout<<"\nA[4] is same as *(A+4) ="<<*(A+4)<<"\n\n";   //*(A+4) is same as A[4]
}

void forEach1(){        //basic  ,foresch loop
    int B[6]={1,2,3,4};  
    for(int x:B){         
        cout<<"B's Element is "<<x<<"\n";       
    }                           
    //for each loop ,useful for collection ,readed as foreach x in B ,benefit : no explicit size needed.
    //iteration depends on size of array,not no. of elements in array.
    //foreach loop dont work on pointers.
    //can also write for(auto x:B){} ,dont need to mention type.
    cout<<"\n";
}

void forEach2(){        //typecasting
    //size 4 array will be created.
    char C[]={'A',66,'C',68};
    for(int x:C)            
        cout<<"C[i] typecasted to int is "<<x<<"\n"; 
    //foreach loop can typecast values if needed. eg.float to int or char to int.   
    cout<<"\n";  
}

void forEach3(){
    int D[]={8,6,3,9,7,4};
    //if you want to reflect changes from foreach in array ,use foreach with reference.
    for(int &x:D){          
        x++;
        cout<<"After increment D[i] is "<<x<<"\n";
    } 
    cout<<"\n";
}

void ArraySum(){
    int A[5]={1,2,3,4,5};
    int sum=0;
    for(int x:A){
        sum+=x;
    }
    print(A,5);
    cout<<"Addition of Array Element is : "<<sum<<"\n\n";
}

void MaxEle(){

}

void linearSearch(){

}

void BinarySearch(){

}
void NestedForLoops(){
    cout<<"Nested for Loop is (i,j) : \n";
    for(int i=1;i<6;i++){
        for(int j=1;j<6;j++){
            cout<<"("<<i<<","<<j<<") ";
        }
        cout<<"\n";
    }
}

int main(){
    // arr1();
    // forEach1();
    // forEach2();
    // forEach3(); 
    // ArraySum();  
    // NestedForLoops();
    //
    //pattern questions     
    //

}