#include<iostream>
using namespace std;
#define line(msg) cout<<"____________________"#msg"______________________\n"
namespace nm64
{
	template<typename T>
	void VendorFun(T obj)
	{
		cout << "vendor job started T [ " << typeid(T).name() << " ]\n";;
		obj();//callback
		cout << "vendor job completed\n";
		line();
	}

	//--------------------------------
	using FPTR = void(*)();

	void ClientFun()
	{
		cout << "Hi I am from client\n";
	}

	void Fun()
	{
		cout << "Haaaaaaaaaaaaaaa\n";
	}

	class CA//functor / function object
	{
		int a{ 0 };
		int b{ 0 };
	public:
		CA(int a, int b) :a(a), b(b)
		{
		}
		void operator()()
		{
			cout << "CA Client Code a : " << a << " b=" << b << '\n';
		}
	};

	int main()
	{
		FPTR fp1 = ClientFun;
		FPTR fp2 = Fun;
		VendorFun(fp1);
		VendorFun(fp2);
		CA obj(102, 103);
		VendorFun(obj);


		return 0;
	}

}