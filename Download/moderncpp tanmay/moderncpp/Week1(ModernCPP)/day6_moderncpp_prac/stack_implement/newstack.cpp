#include<iostream>

template<typename T>
class Stack{
    private:
        T curr_size {0};
        T m_size {0};
        T *arr {nullptr};
        
    public:
        //T Stack()=default;
        Stack(){}
        Stack(T size){
            this->m_size = size;
            this->arr = new T[this->m_size];
        }
        void push(T val){
            this->arr[this->curr_size] = val;
            this->curr_size+=1;
        }
        T pop(){
            this->arr[this->curr_size] = 0;
            this->curr_size-=1;
            return this->arr[this->curr_size];
        }

};

int main(){
    Stack<int>s1(2);
    s1.push(1);
    s1.push(2);
    std::cout<<s1.pop();
    std::cout<<s1.pop();
}
