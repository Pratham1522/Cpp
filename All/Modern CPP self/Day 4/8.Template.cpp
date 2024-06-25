#include<iostream>
using std::cout;
#define line(msg)   cout<<"--------------(msg)--------------------\n";

template<typename T>
T addFun(T x,T y)
{
    //rtti -> runtime type identification
    cout<<"AddFun for T = ["<<typeid(T).name()<<"]\n";
    return x+y;
}
template<typename T1,typename T2>
T2 subFun(T1 x,T1 y)
{
    cout<<"SubFun for T1 =["<<typeid(T1).name()<<"] and T2=[" << typeid(T2).name()<<"]\n";
    return x+y;
}
template<typename T1,typename T2>
auto MulFun(T1 x,T2 y)->decltype(x*y)
{
    cout<<"MulFun for T1 =["<<typeid(T1).name()<<"] and T2=[" << typeid(T2).name()<<"]\n";
    return x*y;
}
class CA{
    public:
    CA operator+(const CA& par)
    {
        return CA();
    }
};
int main()
{
    //T is deduced to int
    static_assert(std::is_same<double,decltype(MulFun(12,3))>());
    static_assert(std::is_same<double,decltype(MulFun(12,3))>(),"Unexpected type Emerged at Pune");
    int x=addFun(3,4);
    //T is deduced to float
    double z= addFun(1.2,3.8);
    CA obj;
    CA ob = addFun(obj,obj);
    line();

    //explicitly deduced para
    double d=subFun<int,double> (10,20);
    line();
    auto e=MulFun(10,5.5);
    cout<<"e =["<<typeid(e).name()<<"]\n";
    line();
    return 0;
}