#include<list>
#include<functional>
#include<numeric>
#include<vector>
#include "CB.hpp"

#define line() cout<<"----------------------------------\n";

template<typename Func ,typename... T>
void print_args(Func fn ,T&& ...t)
{
    (fn(std::forward<T>(t)),...);  
    std::cout<<"\n";
}

template<typename T,typename... T1>
auto GetVal(T t, T1&&... t1)
{
    return (std::invoke(t,std::forward<T1>(t1)...));
}

void Change_List(std::list<int>& lst)
{
    std::iota(lst.begin(), lst.end(), 10);
	std::vector<std::reference_wrapper<int>> vec(lst.begin(), lst.end());
	std::transform(lst.begin(), lst.end(), lst.begin(), [](int num) {return num * 10; });
	cout<<"Elements of list are : ";
    for (auto& rng : lst)
		{
			cout << rng << '\t';
		}
		cout << '\n';
}

int main()
{
    print_args([](const auto& arg) {cout << arg << '\t'; }, "hello", 123, 3.141, 'c');
    line();

    CB obj;
    // cout<<&CB::a<<'\n';
    cout << GetVal(&CB::a, obj) << '\n';
    cout << GetVal(&CB::b, obj) << '\n';
    cout << GetVal(&CB::c, obj) << '\n';
    GetVal(&CB::PrintX, obj, 123);
    GetVal(obj, 888);
    line();

    std::list<int> lst(7);
    Change_List(lst);
    return 0;
}

