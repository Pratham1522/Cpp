#include<iostream>
#include<functional>
using namespace std;
#define line(msg) cout<<"___________________"#msg"____________________\n"

namespace nm78
{
	void Vendor(std::function<void()> obj)
	{
		cout << "start\n";
		obj();
		cout << "stop\n";
		line();
	}



	//------------------

	void fun()
	{
		cout << "client fun\n";
	}

	class FUNC
	{
	public:
		void operator()()
		{
			cout << "FUNC fun\n";
		}
	};

	int main1()
	{
		Vendor(fun);
		FUNC fnc;
		Vendor(fnc);
		Vendor([]() {cout << "Lambda \n"; });
		return 0;
	}

	void Vendor1(std::function<void(int, int)> obj)
	{
		cout << "start1\n";
		//service cuure
		obj(80, 5.00);
		cout << "stop1\n";
		line();
	}

	void fun1(int x, int y)
	{
		cout << "client fun x : " << x << ",y=" << y << '\n';
	}

	int main2()
	{
		Vendor1(fun1);
		Vendor1([](int x, int y) {	cout << "client lambda x : " << x << ",y=" << y << '\n'; });
		return 0;
	}


	void Vendor2(std::function<int(int, int)> obj)
	{
		cout << "start2\n";
		//service cuure
		int res = obj(80, 5.00);
		cout << "stop2 : res : " << res << '\n';
		line();
	}

	int fun2(int x, int y)
	{
		cout << "client fun x : " << x << ",y=" << y << '\n';
		return x + y + 10;
	}

	int main3()
	{
		Vendor2(fun2);
		Vendor2([](int x, int y) {	cout << "client lambda x : " << x << ",y=" << y << '\n'; return 1000; });
		Vendor2([](int x, int y)->int {	cout << "client lambda x : " << x << ",y=" << y << '\n'; return 3.14; });
		Vendor2([](int x, int y)mutable ->int {	cout << "client lambda x : " << x << ",y=" << y << '\n'; return 3.14; });
		return 0;
	}



	void Vendor3(std::function<int(int)> obj)
	{
		cout << "start3\n";
		int res = obj(80);
		cout << "stop3 : res : " << res << '\n';
		line();
	}
	int ClientFun(int x, int y)
	{
		cout << "client fun x : " << x << ",y=" << y << '\n';
		return x + y + 10;
	}
	int main()
	{
		int i = 999;
		using FPTR = int(*)(int, int);
		FPTR fp1 = ClientFun;
		//auto fnc = [i, fp1](int venPar) {return fp1(i, venPar); };
		auto fnc = [i, fp1](int venPar) {return fp1(venPar, i); };
		Vendor3(fnc);
		line();
		std::function<int(int)> fnc1 = std::bind(&ClientFun, i, placeholders::_1);
		Vendor3(fnc1);
		std::function<int(int)> fnc2 = std::bind(&ClientFun, placeholders::_1, i);
		Vendor3(fnc2);

		return 0;
	}
}