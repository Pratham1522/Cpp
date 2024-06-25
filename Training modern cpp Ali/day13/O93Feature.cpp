#include<iostream>
#include<tuple>
#include<set>
#include<map>
using namespace std;

namespace nm93
{
	tuple<int, float, double> f3()
	{
		cout << "f3 called \n";
		return { 100, 1.2f, 3.14159 };
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
	};

	int main1()
	{
		auto t1 = f3();
		//structured binding c++17
		auto [i, j, k] = t1;
		cout << i << '\t' << j << '\t' << k << '\n';
		CA obj;
		obj.Display();
		//auto [a, b] = obj;
		auto& [a, b] = obj;
		//const auto &[a, b] = obj;
		cout << a << '\t' << b << '\n';
		a = 100;
		b = 200;
		obj.Display();
		return 0;
	}

	struct S {
		int n;
		std::string s;
		float d;
		bool operator<(const S& rhs) const
		{
			// compares n to rhs.n,
			// then s to rhs.s,
			// then d to rhs.d
			return std::tie(n, s, d) < std::tie(rhs.n, rhs.s, rhs.d);
		}
	};
	//g++ -std=c++17
	int main2()
	{
		std::set<S> set_of_s; // S is LessThanComparable

		S value{ 42, "Test", 3.14 };
		std::set<S>::iterator iter;
		bool inserted;

		// unpacks the return value of insert into iter and inserted
		std::tie(iter, inserted) = set_of_s.insert(value);

		if (inserted)
			std::cout << "Value was inserted successfully\n";
		return 0;
	}

	int main3()
	{
		std::set<S> set_of_s;

		S value{ 42, "Test", 3.14 };

		auto [iter, inserted] = set_of_s.insert(value);

		if (inserted)
			std::cout << "Value was inserted successfully\n";
		return 0;
	}

	int main4()
	{
		std::set<S> set_of_s;
		S value{ 42, "Test", 3.14 };
		if (auto [iter, inserted] = set_of_s.insert(value); inserted)
			std::cout << "Value was inserted successfully\n";
		return 0;
	}


	int main5()
	{
		std::map<std::string, int> map;
		map["hello"] = 1;
		map["world"] = 2;

		pair<std::map<std::string, int>::iterator, bool> ret = map.insert(pair("India", 20));
		if (ret.second)
		{
			cout << "Sucessfull inserted " << ret.first->first << '\n';
		}

		if (auto [iter, inserted] = map.insert({ "Bharath", 10 }); inserted)
			cout << "Sucessfull inserted " << iter->first << '\n';

		//// initialize the condition we want to check from within the if statement
		if (auto ret = map.insert({ "hello", 3 }); !ret.second)
			std::cout << "hello already exists with value " << ret.first->second << "\n";

		//// ret has not leaked, so we can use that for this conditional check too
		if (auto [iter, inserted] = map.insert({ "foo", 4 }); !inserted)
			std::cout << "foo already exists with value " << iter->second << "\n";


		std::map<std::string, int>::iterator it1 = map.begin();
		std::map<std::string, int>::iterator it2 = map.end();

		for (; it1 != it2; it1++)
		{
			cout << it1->first << '\t' << it1->second << '\n';
		}
		cout << "___________________________________\n";
		for (const auto& rng : map)
		{
			cout << rng.first << '\t' << rng.second << '\n';
		}
		cout << "___________________________________\n";
		for (auto& [k, v] : map)
		{
			cout << k << '\t' << v << '\n';
		}
		cout << "___________________________________\n";


		return 0;
	}

	enum Result
	{
		SUCCESS,
		DEVICE_FULL,
		ABORTED
	};

	std::pair<size_t, Result> writePacket()
	{
		return { 100, SUCCESS };
	}

	int main()
	{
		switch (auto res = writePacket(); res.second)
		{
		case SUCCESS:
			std::cout << "successfully wrote " << res.first << " bytes\n";
			break;
		case DEVICE_FULL:
			std::cout << "insufficient space on device\n";
			break;
		case ABORTED:
			std::cout << "operation aborted before completion\n";
			break;
		}
		return 0;
	}
}