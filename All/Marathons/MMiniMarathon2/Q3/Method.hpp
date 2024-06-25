#include <iostream>
#include <tuple>
using namespace std;


auto addFun = [](int x,int y)
{
    return x+y ;
};
auto sum2 = [](auto first, auto second)
{
    return first + second;
};

template<typename...>
class MyMethod;

template<>
class MyMethod<>
{
public:
    void addFun()
    {
        cout << "Base AddFun\n";
    }
};

template<typename T1, typename... T2>
class MyMethod<T1, T2...> :public MyMethod<T2...>
{
public:
    using MyMethod<T2...>::addFun;
    void addFun(T1 x, T1 y)
    {
        cout << "AddFun T1 '{" << typeid(T1).name() << "}' Called \n";
    }
};

template<typename... T>
ostream& operator<<(ostream& outstream, tuple<T...>const& tup)
{
	std::apply([&outstream](T const&... tupArgs) 
    {
		outstream << "{ ";
		size_t i{ 0 };
		((outstream << tupArgs << (++i != sizeof...(T) ? "  ," : "")), ...);
		}, tup);

	outstream << " }\n";
	return outstream;
}
