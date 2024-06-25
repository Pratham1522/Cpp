#include<iostream>

class parent{
    private:
        int a;
    public:
        virtual void Display()=0;
};

class child1:public parent{
    public:
        void Display(){
            std::cout<<"helo";
        }
};

class child2:public parent{
    public:
        int x;
};

int main(){
    parent p;
    // child2 c2;
    child1 c1;
}
