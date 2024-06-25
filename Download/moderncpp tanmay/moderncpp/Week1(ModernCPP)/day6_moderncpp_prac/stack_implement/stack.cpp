#include<iostream>
#include<string>

template<typename T>
class stack
{
private:
    T current_size {0};
    T m_size {0};
    T *arr;

public:
    template<typename T> stack(){
        this->arr = new stack[4];
        this->m_size = 4;
    }
    template<typename T> stack(T size){
        this->arr = new T[size];
        this->m_size = size;
    }
    bool isempty(){
        if(this->current_size==0) return true;
        return false;
    }
    bool isfull(){
        if(this->current_size==this->m_size) return true;
        return false;
    }
    void push(T value){
        if(!isfull()){
            this->arr[this->current_size] = value;
            this->current_size++;
        }
    }
    T pop(){
        if(isempty()){
            std::cout<<"stack is empty do not pop.\n";
        }
        else{
            this->arr[current_size]=0;
            this->current_size--;
        }
    return this->arr[this->current_size];
    }
};

int main(){
    stack<int> *st = new stack<int>(4);
    st->push(123);
    st->push(345);
    // st->push("xyz");
    // st->push("123");
    std::cout<<st->pop();
    std::cout<<st->pop();
    std::cout<<st->pop();
}

