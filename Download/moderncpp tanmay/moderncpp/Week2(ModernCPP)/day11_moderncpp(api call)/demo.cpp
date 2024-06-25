#include<iostream>

class demo
{
private:
    int* m_values;
    std::size_t m_size;
public:
    demo(/* args */) {}
    ~demo() {}
};

template<typename T>
class wrapper{
    private:
        T* m_ptr;
    public:
        ~wrapper(){
            delete m_ptr;
        }
};


/* 
    1) destructor is always triggered before object is destroyed.

    step a) I will make one object of class Data
        Data* d = new Data(....)
        [10   20   30]
        ^
        |
        |
        [0x100H |   3]
        step b) thisobject's pointer will be saved in the wrapper inside m_ptr
        [       [0x111H]    ]
        step c) when wrapper objects goes out of scope, dest of wrapper will be called
        delete data object!!
        step d) since delete was called on a class type, dest of that particular 
        class will be called
*/