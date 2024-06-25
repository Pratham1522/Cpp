#include<iostream>
#include<functional>
#include<string>
using namespace std;
#define line(msg) cout<<"___________________"#msg"____________________\n"

namespace nm106
{
	template<typename FN>
	void print_args(FN fn)
	{

	}

	template<typename FN, typename T, typename... PCK>
	void print_args(FN fn, T val, PCK&&... pck)
	{
		fn(std::forward<T>(val));
		print_args(fn, std::forward<PCK>(pck)...);
	}

	//c++17
	//
	//template<typename FN,typename... PCK>
	//void print_args(FN fn, PCK&&... pck)
	//{
	//	(fn(std::forward<PCK>(pck)), ...);
	//}



	int main1()
	{

		print_args([](const auto& arg) {cout << arg << '\t'; }, "hello", 123, 3.141, 'c');

		return 0;
	}

	void PrintMe(int i)
	{
		cout << "PrintMe i: " << i << '\n';
	}

	class CA
	{
	public:
		int x_;
		CA(int x) :x_(x)
		{
		}
		void PrintX(int y) const
		{
			cout << "PrintX x : " << x_ + y << '\n';
		}
		void operator()(int i) const
		{
			cout << "CA() i = " << i << '\n';
		}
	};


	int main2()
	{
		std::invoke(PrintMe, 1000);
		line();
		std::invoke([]() {PrintMe(999); });
		line();
		const CA obj(888);
		std::invoke(&CA::PrintX, obj, 222);
		line();
		cout << "x_ = " << std::invoke(&CA::x_, obj) << '\n';
		line();
		std::invoke(obj, 666);
		line();
		std::invoke([](int par) {cout << "Hello " << par << '\n'; }, 10000);
		line();
		std::invoke([](int par) {cout << "Hello " << par << '\n'; }, std::invoke(&CA::x_, obj));
		return 0;
	}


	struct CB
	{
		int a{ 1000 };
		int b{ 2000 };
		int c{ 3000 };
		void PrintX(int y) const
		{
			cout << "PrintX x : " << a + b + c + y << '\n';
		}
		void operator()(int i) const
		{
			cout << "CB() i = " << i << '\n';
		}
	};


	template<typename T1, typename... T2>
	auto GetVal(T1 what, T2&&... where)
	{
		return std::invoke(what, std::forward<T2>(where)...);
	}

	int main()
	{
		CB obj;
		cout << GetVal(&CB::a, obj) << '\n';
		cout << GetVal(&CB::b, obj) << '\n';
		cout << GetVal(&CB::c, obj) << '\n';
		GetVal(&CB::PrintX, obj, 123);
		GetVal(obj, 888);
		return 0;
	}
}