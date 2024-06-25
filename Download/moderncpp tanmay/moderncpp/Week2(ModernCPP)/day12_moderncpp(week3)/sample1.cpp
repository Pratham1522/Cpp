/* 
    WHY??

    OPTIMIZATION
    PROCESSOR : SILICON CHIP WHICH CONTAINS REGISTERS, CACHE...
    CORES : THEY ARE THE PHYSICAL SECTIONS INSIDE THE PROCESSOR
    EACH CORE IS CAPABLE OF HANDLING ONE PROCESS!!
    CLOCK SPEED : instructions per seconds
    THREAD : Set of instructions that occupy memory and represent one isolated, independently executable section of process







    Every process gets 1 unit of time before it is switched for a different process
    let's say ./app is a process got 1 unit of time
    before 1 unit of time has passed, there is a delay in the process which can be (I/O delay or CPU delay) 
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    void F1(){user input; square}

    void F2(){first 5 natural number cube}

    int main(){}

    4 cores:
    3 cores i.e. F1 F2 and main are running out of 4 are mapped
        Maybe 2 threads got mapped to  2cores, 1 is waiting!!
        maybe 1 thread got mapped to 1 core, 2 threads are waiting!!
    

*/
#include<iostream>
#include<thread>
#include<mutex>

std::mutex mt;

void sqaure(int* arr, std::size_t N){
    for(int i=0;i<N;i++){
        std::lock_guard<std::mutex> lk(mt);
        std::cout<<"square is: "<<arr[i]*arr[i]<<std::endl;
    }
}
void Cube(int *arr,std::size_t N){
    for(int i=0;i<N;i++){
        std::lock_guard<std::mutex> lk(mt);
        std::cout<<"cube is: "<<arr[i]*arr[i]*arr[i]<<std::endl;
    }
}

int main(){
    int arr[] = {1,2,3,4,5};
    std::thread t1(&sqaure,std::ref(arr),5);

    std::thread t2(&Cube,std::ref(arr),5);

    //after creation of t2 many scenarios can be encountered!!
    //scenario 1: t1 is already completed by the time t2 is even started
    //scenario 2: t2 and t2 are yet to be completed and running in the background
    if(t1.joinable()){
        t1.join();//main thread should now wait till t1 is finished!!(block till t1 is finished)

    }
    if(t2.joinable()){
        t2.join();//main thread should now wait till t2 is finished!!(block till t2 is finished)
    }
    std::cout<<"goodbye\n";//can only execute after t1 and t2 is finished!!
}

/* 
    |   |   MAIN STARTS
    START---------> ------------------------>          -------------->
    |   |   |   [t1 is created]               [t2 create]
    |   |   |   |
    |   |   |   |
                |
                -------------->cout & sleep
                [t1]
*/

/*
 Buffers : dedicated memory space 
                                   
*/