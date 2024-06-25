#include<iostream>
using namespace std;
#define line(msg) cout<<"________________"#msg"______________________\n"

namespace nm44
{
	auto Sum()
	{
		return 0;
	}

	template<typename T1, typename... T>
	auto Sum(T1 p, T... par)//pack recieved
	{
		return p + Sum(par...);//unpacking
	}

	int main1()
	{
		cout << Sum(1, 2, 3, 4, 5, 6, 7, 8, 9) << '\n';
		cout << Sum(1, 2, 3, 4, 5) << '\n';
		return 0;
	}

	class CA
	{
	public:
		CA()
		{
			cout << "Default \n";
		}
		CA(const CA& par)
		{
			cout << "Copy\n";
		}
		CA(CA&& par) noexcept
		{
			cout << "Move\n";
		}
		~CA() noexcept
		{
			cout << "D-tor\n";
		}
	};

	void f1(int a)
	{
		cout << "f1(int) a=" << a << '\n';
	}

	void f1(int a, int b)
	{
		cout << "f1(int,int) a=" << a << " ,  b=" << b << '\n';
	}

	void f1(int a, int b, CA&& par)
	{
		cout << "f1(int,int,CA) a=" << a << " ,  b=" << b << '\n';
	}

	template<typename... PCK>
	void Wrapper(PCK... pck)
	{
		line();
		//f1(pck...); //error bcoz pck by default has CA not CA&&
		f1(std::forward<PCK>(pck)...);
	}

	int main()
	{
		CA obj1;
		//Wrapper(10);
		//Wrapper(10,20);
		Wrapper(10, 20, std::move(obj1));
		return 0;
	}
}
