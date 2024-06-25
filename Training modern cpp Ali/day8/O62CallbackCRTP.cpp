#include<iostream>
using namespace std;
#define line(msg) cout<<"____________________"#msg"______________________\n"
namespace nm62
{
	//CRTP -> curiously recurring templatepattern
	template<typename T>
	class CVendor
	{
	public:
		void VendorFun()
		{
			cout << "vendor job started\n";
			((T*)this)->ClientFun();//client code
			cout << "vendor job completed\n";
			line();
		}
	};

	//--------------------------------
	class CAT :public CVendor<CAT>
	{
		int a{ 0 };
		int b{ 0 };
	public:
		CAT(int a, int b) :a(a), b(b)
		{
		}
		void ClientFun()
		{
			cout << "CAT called a : " << a << " b : " << b << '\n';
		}
	};

	class DOG :public CVendor<DOG>
	{
		int a{ 0 };

	public:
		DOG(int a, int b) :a(a + b)
		{
		}
		void ClientFun()
		{
			cout << "DOG called a : " << a << '\n';
		}
	};


	int main()
	{
		CAT cat(111, 222);
		DOG dog(10, 20);

		cat.VendorFun();
		dog.VendorFun();

		return 0;
	}
}
