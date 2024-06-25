#include<iostream>
#include<tuple>
using namespace std;

namespace nm92
{
	tuple<int, float, double> f1()
	{
		cout << "f1 called \n";
		tuple<int, float, double> tup = make_tuple<int, float, double>(100, 1.2f, 3.14159);
		return tup;
	}

	auto f2()
	{
		cout << "f2 called \n";
		tuple<int, float, double> tup(100, 1.2f, 3.14159);
		return tup;
	}
	tuple<int, float, double> f3()
	{
		cout << "f3 called \n";
		return { 100, 1.2f, 3.14159 };
	}
	int main1()
	{
		tuple<int, float, double> t1 = f3();
		cout << std::get<0>(t1) << '\t' << std::get<1>(t1) << '\t' << std::get<2>(t1) << '\n';
		auto t2 = f2();
		int i;
		float j;
		double k;
		std::tie(i, j, k) = t2;
		cout << i << '\t' << j << '\t' << k << '\n';
		cout << std::get<0>(t2) << '\t' << std::get<1>(t2) << '\t' << std::get<2>(t2) << '\n';
		std::get<0>(t2) += 1000;
		cout << std::get<0>(t2) << '\t' << std::get<1>(t2) << '\t' << std::get<2>(t2) << '\n';
		int i1;
		double k1;
		std::tie(i1, std::ignore, k1) = t2;
		cout << i1 << '\t' << k1 << '\n';
		int& i2 = std::get<0>(t2);
		i2 += 1000;
		cout << std::get<0>(t2) << '\t' << std::get<1>(t2) << '\t' << std::get<2>(t2) << '\n';
		return 0;
	}

	class CA
	{
	public:
		int i{ 0 };
		int j{ 0 };
		void Display()
		{
			cout << "Display i = " << i << " , j = " << j << '\n';
		}
		operator tuple<int, int>()
		{
			return { i,j };
		}
		operator tuple<int&, int&>()
		{
			return { i,j };
		}
	};

	int main2()
	{
		int x = 10, y = 20;
		cout << x << '\t' << y << '\n';
		std::tie(x, y) = std::make_tuple(y, x);
		cout << x << '\t' << y << '\n';
		CA obj{ 111,222 };
		std::tie(x, y) = (tuple<int, int>)obj;
		cout << x << '\t' << y << '\n';
		tuple<int, int> t1 = obj;
		std::tie(x, y) = t1;
		cout << x << '\t' << y << '\n';
		int& x1 = x;
		int& y1 = y;
		std::tie(x1, y1) = obj;
		cout << x1 << '\t' << y1 << '\n';
		x1 += 100;
		y1 += 100;
		obj.Display();
		cout << x1 << '\t' << y1 << '\n';
		cout << x << '\t' << y << '\n';
		return 0;
	}

	struct CB
	{
		int i{ 100 };
		int j{ 200 };
		operator tuple<int, int>()
		{
			return { i + 1,i + 2 };
		}
		operator tuple<int&, int&>()
		{
			return { i,j };
		}
	};

	int main()
	{
		CB obj;
		int x, y;
		std::tie(x, y) = obj;
		cout << x << '\t' << y << '\t';
		return 0;
	}
}