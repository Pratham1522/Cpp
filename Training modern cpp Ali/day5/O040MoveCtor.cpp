#include<iostream>
using namespace std;
#define line(msg) cout<<"________________"#msg"______________________\n"

namespace nm40
{
	class CA
	{
		int* a;
	public:
		CA() :a(new int(1000))
		{
			cout << "Ctor a = [ " << a << " ]\n";
		}
		CA(const CA& par) :a(new int(*par.a))
		{
			cout << "Deep Copy a= [ " << a << " ]\n";
		}
		CA(CA&& par) noexcept :a(par.a)
		{
			//this  == rvalue objects address
			//par  === temp
			par.a = NULL;
			cout << "Move ctor\n";
		}
		~CA() noexcept
		{
			cout << "D-tor a = [ " << a << " ]\n";
			delete a;
		}
	};

	//g++  -fno-elide-constructors
	CA Factory()
	{
		CA temp;
		cout << "DoBusiness\n";
		return temp;
	}

	int main()
	{
		CA obj = Factory();
		line();
		CA obj1(obj);
		line();
		return 0;
	}
}
