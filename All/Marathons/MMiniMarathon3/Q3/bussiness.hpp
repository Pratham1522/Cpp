#include "complex.hpp"
#define line() cout<<"--------------------------- \n";

template <typename... PCK>
auto sum1(PCK &&... packet)
{
    return (std::forward<PCK>(packet) + ...);
}

template <typename... PCK>
void ShowAll(PCK &&... packet)
{
    ((cout << std::forward<PCK>(packet) << '\t'), ...) << '\n'; 
}
template<typename T, typename ... PCK>
void PushAll(vector<T> &vec,PCK &&... packet)
{
    (vec.push_back(std::forward<PCK>(packet)), ...);
}

template<typename T>
ostream &operator<<(ostream &ot, vector<T> &vec)
{
    for(size_t i=0; i< vec.size(); i++)
    {
        ot<< vec[i]<<'\t';
    }
    ot <<'\n';
    return ot;
}

void start()
{
    line();
    auto res = sum1(10,20,30,40,50,60,70);
    cout << "res is " << res << '\n';

    auto res1= sum1(10,20,30);
    cout << "res is " << res1 <<'\n';

    line();
    cout<<"Showing all : ";
    ShowAll(1.2 ,"Sachin" , 3.14f , 'c' ,1,2,3);
    cout<<"Showing all : ";
    ShowAll(1,2,3);

    line();
    CComplex c1(10,20);
    CComplex c2(20,40);

    CComplex c3 = c1+c2;

    CComplex c4 = c1 + 10;  //add to img
    CComplex c5 = 10 + c1;  //add to real
    
    double d=(double)c5; //recieves (real+img)

    tuple<double, double> t = c5 ; //recieve real and img

    cout << c1 << c2 << c3 << c4 << c5;
    cout << "Vector args : " << d << '\t' << std::get<0>(t) << std::get<1>(t) << '\n' ;
    
    line();
    vector v1{ 10 };
    PushAll(v1 , 20 , 30 , 40 , 50 , 60 , 70 ,80);
    cout << "Printing Vector : " << v1 << '\n';
    line();
}
