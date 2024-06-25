#include<iostream>

class Stack{
    private:
        int m_size{0};
        int current_size{0};
        int *arr;
    public:
        Stack(int size){
            arr = new int[size];
            m_size = size;
        }
        bool isempty(){
            return (this->current_size==0);    
        }
        bool isfull(){
            return (this->current_size==this->m_size);
        }
        void push(int value){
            if(isfull()){
                std::cout<<"Stack is full.\n";
            }
            else{
                this->arr[current_size] = value;
                this->current_size++;
            }
        }
        int pop(){
            if(isempty()){
                std::cout<<"Stack is empty cannot return element.\n";
            }
            else{
                int last = this->arr[current_size-1];
                this->current_size--;
                return last;
            }
            return -1;
        }
};

int main(){
    Stack *st = new Stack(4);
    st->push(1);
    st->push(2);
    st->push(3);
    st->push(4);
    std::cout<<st->pop();    
    std::cout<<st->pop();    
    std::cout<<st->pop();
    std::cout<<st->pop();
        
    std::cout<<st->pop();
}