#include<iostream>
#include<vector>

class A{
    private:
        B *_b{nullptr};
        int _number{0};
    public:
    A(B *base, int num):    _b{base}, _number{num}{}
};

class B{
    private:
        std::vector<int> marks[5];

};

class C : public A{
    private:
        int x;
        int y;
};

class D : public A{
    private:
        int a;
        int b;
    public:
        D(int a,int b, B *c, int num):  a{a},b{b},A(c,num){}
};

int main(){

}
