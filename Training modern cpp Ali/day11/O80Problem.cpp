#include<iostream>
#include<functional>
using namespace std;
#define line(msg) cout<<"___________________"#msg"____________________\n"

namespace nm80
{
	void VendorFun(std::function<void(int)> fn)
	{
		cout << "Start\n";
		fn(100);//callback
		cout << "Stop\n";
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

	int main()
	{
		Country country;
		std::function<void(int)> fnc = std::bind(&Country::Hindustan, &country, placeholders::_1);
		VendorFun(fnc);
		line();
		std::function<void(Country&, int)>  fnc2 = mem_fn(&Country::AlHindh);

		std::function<void(int)> fnc3 = [&country, &fnc2](int par) { fnc2(country, par); };
		VendorFun(fnc3);
		line();
		return 0;
	}
}