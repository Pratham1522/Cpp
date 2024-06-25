#include<iostream>
using namespace std;
#define line(msg) cout<<"________________"#msg"______________________\n"

// namespace nm37
// {
	template<typename T>
	T AddFun(T x, T y)
	{
		//rtti -> runtime type identification
		cout << "Addfun for T= [ " << typeid(T).name() << " ]\n";
		return x + y;
	}

	template<typename T1, typename T2>
	T2 SubFun(T1 x, T1 y)
	{
		//rtti -> runtime type identification
		cout << "Subfun for T1 = [ " << typeid(T1).name() << " ]\t T2 = [ " << typeid(T2).name() << " ]\n";
		return x + y;
	}

	template<typename T1, typename T2>
	auto MulFun(T1 x, T2 y)->decltype(x* y)  //trailing deduce : c++11 onwards
	{
		cout << "Mulfun for T1 = [ " << typeid(T1).name() << " ]\t T2 = [ " << typeid(T2).name() << " ]\n";
		return x * y;
	}


	template<typename T1, typename T2>
	auto MulFunNew(T1 x, T2 y)->decltype(MulFun(x, y))
	{
		cout << "MulfunNew for T1 = [ " << typeid(T1).name() << " ]\t T2 = [ " << typeid(T2).name() << " ]\n";
		return x * y;
	}


	template<typename T1, typename T2>
	auto MulFunNew14(T1 x, T2 y) //auto return type deduce : c++14
	{
		cout << "MulfunNew14 for T1 = [ " << typeid(T1).name() << " ]\t T2 = [ " << typeid(T2).name() << " ]\n";
		return x * y;
	}


	template<typename T1, typename T2>
	auto MulFunNew14_1(T1 x, T2 y)->double //auto return type deduce : c++14
	{
		int par = 10;
		cout << "MulfunNew14 for T1 = [ " << typeid(T1).name() << " ]\t T2 = [ " << typeid(T2).name() << " ]\n";
		if (10 == par)
		{
			return 3.14;
		}
		return 2;
	}

	struct Shubam
	{
		char c;
		int x;
		double y;
	};

	template<int index = 0>
	auto GetStruct(Shubam& shubam)
	{
		if constexpr (0 == index)
			return shubam.c;
		else if constexpr (1 == index)
			return shubam.x;
		else
			return shubam.y;
	}

	class CA
	{
	public:
		CA operator+(const CA& par)
		{
			return CA();
		}
	};

	int main()
	{
		//static_assert(std::is_same<double, decltype(MulFun(12, 3))>(), "Unexpcted type Emerged at Pune"); T is deduced to int.
		static_assert(std::is_same<double, decltype(MulFun(1.2, 3))>(), "");
		//T is deduced to int
		int x = AddFun(10, 20);
		//T is deduced to double
		double y = AddFun(1.0, 2.0);
		CA obj;
		CA ob = AddFun(obj, obj);
		line();

		double d = SubFun<int, double>(10, 20);
		// auto d1 = SubFun(1.0, 2.0);
		auto m1 = MulFun(2.3, 4);
		cout << "m1= [ " << typeid(m1).name() << " ]\n";

		auto m2 = MulFunNew14_1(1, 2.3);

		Shubam s{ 'c',123 ,3.141 };
		cout << GetStruct(s) << '\n';
		cout << GetStruct<1>(s) << '\n';
		cout << GetStruct<2>(s) << '\n';


		return 0;
	}
}
