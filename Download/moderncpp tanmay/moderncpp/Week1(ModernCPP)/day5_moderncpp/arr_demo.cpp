#include<iostream>
#include<array>

template <typename T>
using Array = std::array<T,5>;

template <typename T>
void Insert(Array<T>& data,const int position,const int val){
    data[position] = val;
}

template <typename T>
void Display(const Array<T>& data){
    for(Array<t>::iterator itr = data.begin();itr!=data.end();++itr){
        std::cout<< *itr<<std::endl;
    }
    std::cout<<"\n";
    //reverse
    for(Array<T>::iterator itr = data.rbegin(); itr!=data.rend();++itr){
        std::cout<<*itr<<std::endl;
    }
}

template <typename T>
int FindElementAtIndexN(const Array<T>& data, unsigned N){
    return data[N];
}


int main(){

}

/* operations:
    1   first item
    2   last item
    3   access random positioned element
    4   access something based on a label
    5   add an element
    6   remove and element* (ATLEAST MAKE PEOPLE BELIEVE THAT)
    7
    */






