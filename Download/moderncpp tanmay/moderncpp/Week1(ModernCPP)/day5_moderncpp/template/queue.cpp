#include<iostream>

class queue
{
private:
    int front{0};
    int back{0};
    int m_size{0};
    int current_size{0};
    int *arr;
public:
    queue(int size){
        arr = new int[size];
        this->m_size = size;
    }
    bool isempty(){
        return (this->current_size==0);
    }
    bool isfull(){
        return (this->current_size==this->m_size);
    }
    int front(){
        return this->arr[0];
    }
    int back(){
        return arr[this->current_size-1];
    }
    void push(int value){
        front = this->arr[0];
        back = value;
        this->arr[current_size] = value;
        this->current_size++;
    }
    int pop(){
        front = this->arr[0];
        
    }
};