#include<iostream>
#include<functional>
using namespace std;
#define line(msg) cout<<"________________"#msg"______________________\n"

namespace nm5
{
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

	template<typename T>
	void f1(T par)
	{
		cout << "T = [ " << typeid(par).name() << " ]\n";
		cout << "Apple\n";
	}

	template<typename T>
	void f2(T& par)
	{
		cout << "f2 T = [ " << typeid(par).name() << " ]\n";
		cout << "Orange\n";
	}

	template<typename T>
	void f3(T&& par)
	{
		cout << "f3 T = [ " << typeid(par).name() << " ]\n";
		cout << "Orange\n";
	}

	template<typename T>
	void reciever(T p)
	{
		cout << "recieved\n";
	}
	template<typename T>
	void Surrogate(T&& par)
	{
		line(InReciever);
		//reciever(par);
		reciever(std::forward<T>(par));
		cout << "Orange\n";
	}

	void test1()
	{
		CA obj;
		line();
		int j = 10;
		f1(10);
		line();
		f1(j);
		line();
		f1(obj); //copy constructor
		line();
	}

	void test2()
	{
		CA obj;
		line();
		int j = 10;
		//f2(10);  //cant pass constant to reference
		line();
		f2(j);
		line();
		f2(obj);
		line();
	}

	void test3()
	{
		CA obj;
		line(1);
		int j = 10;
		f3(10);  // can pass constant to move
		line(j);
		f3(ref(j));
		line(ref(j));
		f3(j);
		line(obj);
		f3(obj);
		line(ref(obj));
		f3(std::ref(obj));
		line(move(obj));
		f3(std::move(obj));
		line(6);
	}
	void test4()
	{
		CA obj;
		line();
		//Surrogate(10);
		line();
		//int j = 10;
		//Surrogate(j);
		line(copyFromMain);
		Surrogate(obj);
		line(moveFromMain);
		Surrogate(std::move(obj));
		line();
	}
	int main()
	{
		//test1();
		//test2();
		//test3();
		test4();

		return 0;
	}
}
