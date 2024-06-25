#include<iostream>
using namespace std;
#define line(msg) cout<<"________________"#msg"______________________\n"

namespace nm36
{
	//name decoration/mangling
	void fun()
	{
	}

	void fun(int)
	{
	}
	//calling convention
	extern "C++" void fun(int, int)
	{
	}

	extern "C" void fun1()
	{
	}

	//
	//extern "C" void fun1(int)
	//{
	//}


	constexpr int fib(int n)
	{
		return (n < 2) ? n : (fib(n - 1) + fib(n - 2));
	}

	template<int num>
	class Stack
	{
	};

	//---------------------------------------
	int main1()
	{
		fun();
		fun(10);
		fun(10, 20);
		fun1();
		//fun1(10);

		int arr[10];
		int arr1[fib(5)];
		Stack<5> stk1;
		Stack<fib(3)> stk2;
		int k = 10;
		int h = fib(k);
		return 0;
	}

	//UDL -> user defined literals
	constexpr long double operator "" _rad(long double deg)
	{
		return 3.14159 / 180.0 * deg;
	}

	int main2()
	{
		constexpr long double angle = 90.0_rad;

		cout << "Angle : " << angle << '\n';
		return 0;
	}

	template<int index>
	void GetMe()
	{
		cout << "Apple\n";
		if constexpr (0 == index)
		{
			cout << "Bhindi\n";
		}
		else if constexpr (1 == index)
		{
			cout << "Palak\n";
		}
		else
		{
			cout << "Bottle Guord\n";
		}
		cout << "Orange\n";
	}

	int main()
	{
		GetMe<0>();
		GetMe<1>();
		GetMe<2>();

		return 0;
	}
}