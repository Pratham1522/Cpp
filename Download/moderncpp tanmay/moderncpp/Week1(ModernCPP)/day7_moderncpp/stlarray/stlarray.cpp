#include<iostream>
#include<array>

/* void Magic(std::array<int,5>& arr){
    for(std::array<int,5>::reverse_iterator itr = arr.rbegin(); itr!=arr.rend();++itr){
        std::cout<<*itr<<"\n";
    }
} */

void Magic(std::array<int,5>& arr){
    for(int val:arr){
        std::cout<<val<<"\n";
    }
}

int main(){
    //int arr[5];
    std::array<int,5> arr{0};
    //arrays are accessed by index.
    arr[0] = 100;
    // std::cout<<&arr[0]<<"\n"<<&arr; both print the same address.
    //Magic(arr);
    std::cout<<arr.end();
}


/* 
front() means access to 1st item in the container by reference.
back() access to last item in the container by reference.
begin() iterator to first item in the container.
end() iterator to a non valid location outside of the limits of the container's memory.
cbegin() iterator to the first item in the container
    THIS ITERATOR CANNOT BE DEREFERENCED FOR WRITING.
    const begin()
 
*/
