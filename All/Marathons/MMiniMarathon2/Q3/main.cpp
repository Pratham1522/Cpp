#include "Method.hpp"
#define line() cout<<"-------------------------------------------------\n";

int main()
{
    line();
    //addfun call using apply
    cout<<"addFun(200,300) : "<<std::apply(addFun,make_tuple(100,200))<<'\n';

    line();
    // 2 call sum2 using apply
    cout<<"sum2(10.23, 19.73) : "<<std::apply(sum2,make_tuple(10.23 , 19.73))<<'\n';
    cout<<"sum2(100, 50.5f) : "<<std::apply(sum2,make_tuple(100 , 50.5f))<<'\n';

    line();
    // overload ostream to print tuple value
    std::tuple myTuple(25,"Hello",9.31f,'c');
    std::cout << myTuple << '\n' ;

    line();
    //varaiadic class template
    MyMethod <int, double, float ,char> obj;
    obj.addFun(10,20);
    obj.addFun(1.0,2.0);
    obj.addFun(1.0f ,2.0f);
    obj.addFun('a','c');
    obj.addFun();
    
    line();
    return 0;
}
