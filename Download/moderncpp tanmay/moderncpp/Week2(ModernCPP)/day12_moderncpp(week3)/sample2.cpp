#include<iostream>
#include<thread>
#include<mutex>

std::mutex mt;

void sqaure(int* arr, std::size_t N){
    for(int i=0;i<N;i++){
        std::this_thread::sleep_for(std::chrono::seconds(1));
        
        mt.lock();
        std::cout<<"square is: "<<arr[i]*arr[i]<<"\n";
        mt.unlock();
    }
}
void Cube(int *arr,std::size_t N){
    std::this_thread::sleep_for(std::chrono::seconds(1));
    for(int i=0;i<N;i++){
        mt.lock();
        std::cout<<"cube is: "<<arr[i]*arr[i]*arr[i]<<"\n";
        mt.unlock();
    }
}

int main(){
    int arr[] = {1,2,3,4,5};
    std::thread t1(&sqaure,arr,5);

    std::thread t2(&Cube,arr,5);

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
