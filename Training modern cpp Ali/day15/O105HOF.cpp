#include<iostream>
#include<functional>
#include<string>
#include<list>
#include<numeric>
#include<algorithm>
#include<random>
#include<vector>
using namespace std;
#define line(msg) cout<<"___________________"#msg"____________________\n"

namespace nm105
{
	//using FPTR = void(*)(int&);
	using FPTR = std::function<void(int&)>;
	void Walk(FPTR fp, int* ar, int size)//HOF
	{
		for (size_t i = 0; i < size; i++)
		{
			fp(ar[i]);
		}
	}
	//---------------------------

	void ClientFun(int par)
	{
		cout << par << '\t';
	}
	void ClientFun1(int par)
	{
		cout << par * 10 << '\t';
	}
	void ClientFun2(int& par)
	{
		par *= 2;
	}

	template<typename T>
	void PrintMe(string displaymsg, T& collection)
	{
		//cout << " T : [ " << typeid(T).name() << " ]\n";
		cout << displaymsg << " : ";
		for (auto& rng : collection)
		{
			cout << rng << '\t';
		}
		cout << '\n';
	}

	int main1()
	{
		int arr[6]{ 11,22,33,44,55,66 };
		//Walk(&ClientFun,arr,6);
		//cout << '\n';
		//Walk(&ClientFun1,arr,6);
		//cout << '\n';
		//Walk(&ClientFun2,arr,6);
		//Walk(&ClientFun, arr, 6);
		//cout << '\n';
		//int k = 11;
		//Walk([k](int& par) {par *= k; }, arr, 6);
		//Walk(&ClientFun, arr, 6);

		PrintMe("Elements are : ", arr);
		return 0;
	}


	int main2()
	{
		std::list<int> lst(7);
		std::iota(lst.begin(), lst.end(), 10);

		PrintMe("Elements of list are  are : ", lst);
		line();
		std::for_each(lst.begin(), lst.end(), [](int& par) {par *= 20; });
		PrintMe("Elements of list are  are : ", lst);
		line();
		std::for_each(lst.begin(), lst.end(), [](int& par) {cout << par << '\t'; });

		return 0;
	}


	int main3()
	{
		//c++14 random
		random_device rd; // used to yield seeds
		std::mt19937 gen(rd()); //mersene twister_engine

		std::uniform_int_distribution<> dis(10, 50);
		for (int n = 0; n <= 4; n++)
		{
			cout << dis(gen) << '\t';
		}
		cout << '\n';


		return 0;
	}


	int main4()
	{
		std::list<int> lst(7);
		std::iota(lst.begin(), lst.end(), 10);
		vector<int> vec1(lst.begin(), lst.end());
		PrintMe("Elements of list are : ", lst);
		line();
		PrintMe("Elements of vector1 are : ", vec1);
		line();
		vector<std::reference_wrapper<int>> vec2(lst.begin(), lst.end());
		PrintMe("Elements of vector2 are : ", vec2);
		vec2[2].get() = 999;
		PrintMe("Elements of vector2 are : ", vec2);
		PrintMe("Elements of list are : ", lst);

		return 0;
	}

	void test(std::list<int>& lst)
	{
		std::iota(lst.begin(), lst.end(), 10);
		std::transform(lst.begin(), lst.end(), lst.begin(), [](int par) {return par * 10; });
		vector<std::reference_wrapper<int>> vec(lst.begin(), lst.end());
		PrintMe("Elements of list are : ", lst);
		PrintMe("Elements of vector are : ", vec);
		line();
		std::shuffle(vec.begin(), vec.end(), std::mt19937{ std::random_device{}() });
		line();
		PrintMe("Elements of vector after shuufle are : ", vec);
		line();
		vec[3].get() = 999;
		for (auto& v : vec)
		{
			v *= 10;
		}
		PrintMe("Elements of vector after shuufle are : ", vec);
		line();
	}
	int main()
	{

		std::list<int> lst(7);
		test(lst);
		PrintMe("Elements of list are : ", lst);

		return 0;
	}


	int main6()
	{
		char a = 'K', b = 'i', c = 'l', d = 'l', e = 's';
		int a1{ 10 }, b1{ 20 }, c1{ 30 }, d1{ 40 };
		line();
		reference_wrapper<char> arrayRefs[] = { a,b,c,d,e };
		reference_wrapper<int> intRefs[] = { a1,b1,c1,d1 };

		for (auto& ch : arrayRefs) {
			cout << ch << '\t';
		}
		cout << '\n';
		line();
		for (auto& i : intRefs) {
			cout << i << '\t';

		}
		cout << '\n';

		line();
		arrayRefs[0].get() = 'P';
		cout << "a=" << a << '\n';
		cout << "b=" << b << '\n';
		cout << "c=" << c << '\n';
		cout << "d=" << d << '\n';
		cout << "e=" << e << '\n';
		line();
		intRefs[0].get() = 999;
		cout << "a1=" << a1 << '\n';
		cout << "b1=" << b1 << '\n';
		cout << "c1=" << c1 << '\n';
		cout << "d1=" << d1 << '\n';
		line();
		return 0;
	}

	void fun1()
	{
		cout << "fun1 Apple\n";
	}

	void fun2(int count)
	{
		cout << "fun2 Orange count = " << count << '\n';
	}



	int main7()
	{
		std::reference_wrapper<void()> refFn = fun1;
		refFn();
		auto refFn1 = std::ref(fun1);
		refFn1();
		line();
		//std::function<void()> refFn3 = std::bind(fun2, 100);
		//auto refFn3 = std::bind(fun2, 100);
		//refFn4();


		auto refFn3 = std::bind(fun2, placeholders::_1);
		auto refFn4 = ref(refFn3);
		refFn4(200);
		line();

		int k = 100;
		auto lmd = [k](int x, int y) {cout << "k=" << k << ",x=" << x << ",y=" << y << '\n'; };
		//auto refLmd = std::bind(lmd, placeholders::_2, placeholders::_1);
		std::function<void(int, int)> refLmd = std::bind(lmd, placeholders::_2, placeholders::_1);
		auto refLmdRef = ref(refLmd);
		refLmdRef(101, 102);
		line();
		return 0;
	}


	void Increase(int& i, int& j)
	{
		i += 10;
		j += 10;
	}

	int main8()
	{
		int x = 100, y = 200;
		auto change = std::bind(Increase, ref(x), y);
		change();
		cout << "x=" << x << ",y=" << y << '\n';
		return 0;
	}

	void EraseVector(vector<int>& vec, std::function<bool(int)> fn)
	{
		/*vector<vector<int>::iterator> vecId;
		vector<int>::iterator it1 = vec.begin();
		vector<int>::iterator it2 = vec.end();
		while (it2!=it1)
		{
			if (fn(*it1))
				vecId.push_back(it1);

				it1++;
		}
		for (int i = vecId.size()-1; i >=0; i--)
		{
			vec.erase(vecId[i]);
		}
		*/
		//vec.erase(std::remove(it1,it2,33),vec.end());

		vec.erase(std::remove_if(vec.begin(), vec.end(), fn), vec.end());
	}

	int main9()
	{
		vector<int> vec{ 11,22,33,44,55,66,77,88 };
		EraseVector(vec, [](int par) {return par % 2 == 1; });
		for (auto& v : vec)
		{
			cout << v << '\t';
		}
		cout << '\n';
		return 0;
	}
}