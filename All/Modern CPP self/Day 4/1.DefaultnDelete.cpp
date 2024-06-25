#include<iostream>
using std::cout;
#define line(msg)   cout<<"--------------(msg)--------------------\n";

class CA
{
    public:
    static void* operator new(size_t) = delete;
    static void* operator new[](size_t) = delete;
    static void operator delete(void*) = delete;
    static void operator delete[](void*) = delete;

    CA()=default;

    CA(const CA&)=delete;
    CA& operator = (const CA&)=delete;

    void AddFun(double x,double y)
    {
    }
    void AddFun(int,int)=delete; //dont want to pay for conversion fee:cpu cycles

    void SubFun(double x,double y)
    {
    }
    template<typename T>  //anything except float will be prohibited
    void SubFun(T,T)=delete;
};
int main()
{
    CA obj1;
    //CA obj2(obj1);
    CA obj3;
    //obj1=obj3;

    // CA* obj4 = new CA();
    // delete obj4;

    //CA*obj5 = new A[5];
    //delete [] obj5;

    //obj1.AddFun(10,20);
    obj1.AddFun(1.0,2.0);
    obj1.AddFun(1.0f,2.0f);

    //obj1.SubFun(10,20);
    // obj1.SubFun(1.0f,2.0f);
    obj1.SubFun(1.0,2.0);

}