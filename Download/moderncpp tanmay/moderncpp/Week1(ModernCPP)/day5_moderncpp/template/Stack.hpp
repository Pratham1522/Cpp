#ifndef STACK_HPP
#define STACK_HPP

#include<iostream>
#include "selfstack.hpp"
/* LIFO
give only 1 element.
STACK : fixed or dynamically resizeable
    -internally for storing data what will be your container??

 */
template <typename T>
class Stack
{
private:
    T* _data {nullptr};//array is used as backend for my stack
    int m_top {-1};
    int m_size {0};
public:
    Stack() = default;
    Stack(const Stack<
          inline void Stack::push(int value) {
          } T> &); // deep copy
    Stack<T>& operator=(const Stack<T>&);
    Stack<T>& operator=(const Stack<T>&&)=default;
    Stack(const Stack<T>&&)=default;
    ~Stack();
    Stack(T* elements, int size);
    void Push(T val);
    void Pop();
    T Peek();
    size_t Size();
    void operator+(const Stack<T>& rhs);
};

#endif // STACK_HPP

template <typename T>
inline Stack<T>::Stack(const Stack<T> &rhs)
{
    this->m_top = rhs.m_top;
    this->m_size = rhs.m_size;
    this->m_size = new T[rhs.m_size];
    for(int i=0;i<m_size;i++){
        this->_data[i] = rhs._data[i];
    }
}

template <typename T>
inline Stack<T> &Stack<T>::operator=(const Stack<T> &)
{
        this->m_top = rhs.m_top;
    this->m_size = rhs._size;
    this->m_size = new T[rhs._size];
    for(int i=0;i<m_size;i++){
        this->_data[i] = rhs._data[i];
    }
    return *this;
}

template <typename T>
inline Stack<T>::~Stack()
{
    if(_data){
        delete[] _data;
    }
}

template <typename T>
inline Stack<T>::Stack(T *elements, int size)
{
    if(m_size<=0){
        throw std::runtime_error("size is invalid");
    }
    _data = new T[size];
    for(int i=0;i<size;i++){
        this->m_top++;
        this->_data[i] = elements._data[i];
    }
    this->m_size = m_size;
}

template <typename T>
inline void Stack<T>::Push(T val)
{
    //_data = new int;
    _data[m_size] = val;
    m_size++;
    top = val;
}

template <typename T>
inline void Stack<T>::Pop()
{
    if(this->m_size == 0){
        throw std::runtime_error("size of stack is zero");
    }
    this->m_top--;
    this->m_size--;
}

template <typename T>
inline T Stack<T>::Peek()
{
    if(_data.empty()){
        throw std::runtime_error("stack is empty");
    }
    return _data[m_size];
}

template <typename T>
inline size_t Stack<T>::Size()
{
    return m_size;
}
