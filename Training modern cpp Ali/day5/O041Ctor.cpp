#include<iostream>
using namespace std;
#define line(msg) cout<<"________________"#msg"______________________\n"

namespace nm41
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

	void f1(CA obj)
	{
		cout << "Apple\n";
	}

	void f2(CA& obj)
	{
		cout << "Orange\n";
	}

	void f3(CA&& obj)
	{
		cout << "Mango\n";
	}

	int main()
	{
		CA obj;   
		line();
		//f1(obj);  // copy constructor
		line();
		//f2(obj);  // no constructor, reference
		line();
		//f1(std::move(obj));
		line();
		//f2(std::move(obj));//error :move inplace of reference
		line();
		//f3(obj);//error : needed explicit move
		line();
		f3(std::move(obj));
		line();
		return 0;
	}

}
