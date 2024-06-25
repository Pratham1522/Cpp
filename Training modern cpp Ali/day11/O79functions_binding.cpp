#include<iostream>
#include<functional>
using namespace std;
#define line(msg) cout<<"___________________"#msg"____________________\n"

namespace nm79
{
	double div1(double x, double y)
	{
		return x / y;
	}
	int main1()
	{
		cout << "2/5=" << div1(2, 5) << '\n';
		cout << "3/6=" << div1(3, 6) << '\n';
		cout << "7/2=" << div1(7, 2) << '\n';
		cout << "9/4=" << div1(9, 4) << '\n';
		line();
		std::function<double(double, double)> invDiv1 = std::bind(&div1, std::placeholders::_2, std::placeholders::_1);
		cout << "inv 2/5=" << invDiv1(2, 5) << '\n';
		cout << "inv 3/6=" << invDiv1(3, 6) << '\n';
		cout << "inv 7/2=" << invDiv1(7, 2) << '\n';
		cout << "inv 9/4=" << invDiv1(9, 4) << '\n';
		line();
		std::function<double(double)> half = std::bind(&div1, std::placeholders::_1, 2);
		cout << "2/2=" << half(2) << '\n';
		cout << "3/2=" << half(3) << '\n';
		cout << "7/2=" << half(7) << '\n';
		cout << "9/2=" << half(9) << '\n';
		return 0;
	}


	class Country
	{
	public:
		void Bharath(int x)
		{
			cout << "Bharath x : " << x << '\n';
		}
		void India(int x)
		{
			cout << "India x : " << x << '\n';
		}
		void Hindustan(int x)
		{
			cout << "Hindustan x : " << x << '\n';
		}
		void AlHindh(int x)
		{
			cout << "AlHindh x : " << x << '\n';
		}
	};


	template<typename T>
	class Parmeet
	{
		T fptr;
	public:
		Parmeet(T fptr) :fptr(fptr)
		{
		}
		template<typename T1, typename... T2>
		void operator()(T1&& obj, T2&&... par)
		{
			(obj.*fptr)(std::forward<T2>(par)...);
		}
	};

	template<typename T1>
	auto mem_par1(T1 par)
	{
		return Parmeet<T1>(par);
	}

	int main()
	{
		Country country;
		line();
		//std::function<void(Country&,int)> pt = mem_par1(&Country::Bharath);
		//pt(country, 10);

		//mem_par1(&Country::Bharath)(country,10);
		using FPTR = void (Country::*)(int);
		Parmeet<FPTR> parmeet = mem_par1(&Country::Bharath);
		parmeet(country, 100);
		return 0;
	}


	int main2()
	{
		Country country;
		line();
		std::function<void(int)> fnc = std::bind(&Country::Bharath, country, placeholders::_1);
		fnc(100);
		fnc(101);
		fnc(102);

		//std::function<void(int)> fnc = std::bind(&Country::Bharath, placeholders::_1,200);
		//fnc(country);
		std::function<void(Country&, int)> fnc1 = std::mem_fn(&Country::Bharath);
		fnc1(country, 10);
		return 0;
	}
}