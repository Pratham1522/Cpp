#include<iostream>
using namespace std;
void basic(){
    //there are 2 types of variables : data var (int x=10) and address var(int *p; p=&x). 
    //pointer is a variable used to store address of data.
    //code section in memory can only access code section and stack memory directly
    //pointer can be used to access heap storage indirectly by creating a pointer in stack which points to some memory in heap storage.
    int x=10;       //declaratin
    int *p;         //Initialization
    p=&x;
    cout<<"x : "<< x <<"\n";      //x
    cout<<"&x : "<< &x <<"\n";    //address of x
    cout<<"p : "<< p <<"\n";      //address of x
    cout<<"&p : "<< &p <<"\n";    // address of p
    cout<<"*p : "<< *p <<"\n";    //dereferencing : going to pointer location and taking the data.
    
    *p=100;        //change at all places
    //you are changing value stored at some address and x is also pointing to same address to changes reflects.
    cout<<x;

    //pointers are very dangerous and easily prone to runtime errors : uninitialized pointer,memory leak, dangling pointer
    //memory gets deleted from set of memory, resolve using delete []q.

}
void heapMemory(){
    //heap memory is created dynamically at the run time.
    int A[5]={1,2,3,4,5};       //array created in stack memory
    int *b=new int[5];          //array created in heap ,and pointer b in stack ,new keyword is used.
    b[0]=5;
    b[1]=4;
    cout<<*(b+0)<<"\n";
    delete []b;            //now b is dongling pointer.
    b=nullptr;
    

    
    // cout<<*(b+1)<<"\n";  //segmentation error ,
    //stack memory gets deallocated automatically,heap memory does not.
    //remember to delete/deallocate heap memory else memory leak  , delete []p;
    //Null pointer ,not pointing anywhere ,delete[] p ,p=NULL,p=0,p=nullptr.

    //regerence : &;
    /*
    int x=10,a;
    int &y=x;   //reference ,now y is alias for x,both has same address.
    //here also x represents address of memory
    int &y=a   //cant write as y is assigned address once,cant change it.(previousl declared)

    int a;
    a=x   //x in right represents value
    x=25  //here x represents address of memory
    */

    //there can also be a pointer to a function.
    /*
    void display(){
        cout<<"Hello World \n"
    }
    void (*fp)();         //declaration
    fp=display();    //init
    (*fp)(parameters if any)          //call
    */
   //a function pointer can point on any function having same signature eg:max & min of 2 elements
}

void pointerArithematic(){
    int A[5]={2,4,6,8,10};
    int *p=A;
    cout<<*p<<"\n";  //2
    p++;
    cout<<*p<<"\n";   //4
    int *q=&A[3];
    cout<<*q<<"\n";

}

void pointerProblem(){
    //uninitialized ptr
    int *p;   //p is not initialised (not assigned address.)
    *p=25;   //where should p store value 25.
    cout<<*p<<"\n";  //segmentation error
    //sol: int x=10; p=&x;  or  p=(int*)0x65474567  or p=new int[5];

    //memory leak
    //whenever allocate memory, must deallocate after use, else memory is leak from total memory.
    // int *p=new int[5];
    // p=NULL;  // or p=0; or p=nullptr;
    //sol: delete []p;

    //Dangling pointer.
    /*
    void fun(int *q){    //q is pointing to same memory as p
        delete []q;      //q deletes the memory
    }
    void main(){
        int *p=new int[5];    //p pointing to a memoy loc
        fun(p);               
        cout<<*p;              //now p is pointing to memory but it doesnt have value there
    }
    */
}

int main(){
    // basic();
    heapMemory();
    // pointerArithematic();
    // pointerProblem();
    return 0;
}
