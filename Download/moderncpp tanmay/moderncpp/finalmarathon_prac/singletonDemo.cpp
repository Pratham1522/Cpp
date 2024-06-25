#include<iostream>
#include<memory>

//in .h file
using Pointer = std::unique_ptr<Operations>;

class Operations{
    private:
        static Pointer m_instance;
    public:
        static Pointer& GetInstance();
};
//in cpp file
Pointer Operations::m_instance = nullptr;

Pointer& Operations::GetInstance(){
            if(m_instance){
                return m_instance;
            }
            else{
                m_instance.reset(new Operations());
                return m_instance;
            }
        }

//in main
    Pointer& ptr = Operations::GetInstance();
    std::thread(&function,ptr.get());
