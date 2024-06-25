#include<iostream>
using namespace std;
#define line(msg) cout<<"________________"#msg"______________________\n"


namespace nm42
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

	void f1(CA&& obj)
	{
		cout << "f1 Apple\n";
	}

	void Wrapper(CA&& obj)
	{
		cout << "Hi\n";
		f1(std::move(obj));
		cout << "Bye\n";
	}

	int main()
	{
		CA obj1;
		line();
		//Wrapper(obj1);
		line();
		Wrapper(std::move(obj1));
		line();
		line();
		return 0;
	}

}