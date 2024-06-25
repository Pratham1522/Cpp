#include<iostream>
using namespace std;
#define line(msg) cout<<"____________________"#msg"______________________\n"

namespace nm61
{
	class CVendor
	{
	public:
		void VendorFun()
		{
			cout << "vendor job started\n";
			ClientFun();//client code
			cout << "vendor job completed\n";
			line();
		}
	protected:
		virtual void ClientFun() = 0;
	};

	//--------------------------------
	class CAT :public CVendor
	{
		int a{ 0 };
		int b{ 0 };
	public:
		CAT(int a, int b) :a(a), b(b)
		{
		}
	protected:
		void ClientFun() override
		{
			cout << "CAT called a : " << a << " b : " << b << '\n';
		}
	};

	class DOG :public CVendor
	{
		int a{ 0 };

	public:
		DOG(int a, int b) :a(a + b)
		{
		}
	protected:
		void ClientFun() override
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