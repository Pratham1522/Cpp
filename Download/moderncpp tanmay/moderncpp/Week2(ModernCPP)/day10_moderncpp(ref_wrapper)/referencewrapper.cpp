// #include<iostream>
// #include<vector>
// #include<functional>

// /* 
//     reference: an alias or an alterante TO SOMETHING THAT ALREADY EXISTS!
// */

// int main(){
//     //why people dont use regular reference frmo CPP in modern CPP. 
//     //This is similar to why ppl don't use pointers in modern CPP.
//     //problem 1: ref don't exist in memory PHYSICALLY!!! They have no memory footprint.
//     //int& arr[1];
    
//     int n1 = 10;
//     std::reference_wrapper<int> ref {n1};
//     std::reference_wrapper<int> arr[1] {ref};
//     std::vector<std::reference_wrapper<int>> data {ref};
//     std::cout<<arr[1];

// }
