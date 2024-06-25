#include<iostream>
using namespace std;
#define line(msg) cout<<"____________________"#msg"______________________\n"

namespace nm68
{
	template<typename T>
	void VendorFun(T obj)
	{
		cout << "vendor job started\n";
		obj();//callback
		cout << "vendor job completed\n";
		line();
	}

	class CA
	{
		int x{ 10 };
		int y{ 20 };
	public:
		void fun1()
		{
			int a = 111;
			int b = 222;
			//members captured by reference and locals captured by value
			auto fnc = [=]() {
				x += 10;
				//a += 10;//error
				cout << "x=" << x << '\n';
				cout << "y=" << y << '\n';
				cout << "a=" << a << '\n';
				cout << "b=" << b << '\n';
			};
			VendorFun(fnc);
		}

		void fun2()
		{
			int a = 111;
			int b = 222;
			//members captured  and locals captured by reference
			auto fnc = [&]() {
				x += 10;
				a += 10;
				cout << "x=" << x << '\n';
				cout << "y=" << y << '\n';
				cout << "a=" << a << '\n';
				cout << "b=" << b << '\n';
			};
			VendorFun(fnc);
		}


		void fun3()
		{
			int a = 111;
			int b = 222;
			//members captured  by reference
			auto fnc = [this]() {
				x += 10;
				y += 20;
				cout << "x=" << x << '\n';
				cout << "y=" << y << '\n';

			};
			VendorFun(fnc);
		}


		void fun4()
		{
			int a = 111;
			int b = 222;
			//members captured  by value
			auto fnc = [lcl = *this]() {
				//lcl.x += 10;
				//lcl.y += 20;
				cout << "x=" << lcl.x << '\n';
				cout << "y=" << lcl.y << '\n';

			};
			VendorFun(fnc);
		}

		void fun()
		{
			int a = 111;
			int b = 222;
			//members captured  by value
			//auto fnc = [*this]() {//c++17 onwards
			//	//x += 10;
			//	//y += 20;
			//	cout << "x=" << x << '\n';
			//	cout << "y=" << y << '\n';

			//};
			//VendorFun(fnc);
		}
	};

	int main()
	{
		CA obj;
		obj.fun();
		return 0;
	}
}