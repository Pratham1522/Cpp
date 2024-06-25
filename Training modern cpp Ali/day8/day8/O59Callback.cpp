#include<iostream>
using namespace std;
#define line(msg) cout<<"____________________"#msg"______________________\n"

namespace nm59
{
	class IClient
	{
	public:
		virtual void ClientFun() = 0;
	};

	void VendorFun(IClient* client)
	{
		cout << "vendor job started\n";
		client->ClientFun();//client code
		cout << "vendor job completed\n";
		line();
	}

	//--------------------------------

	class CAT :public IClient
	{
		int a{ 0 };
		int b{ 0 };
	public:
		CAT(int a, int b) :a(a), b(b)
		{
		}
		void ClientFun() override
		{
			cout << "CAT called a : " << a << " b : " << b << '\n';
		}
	};

	class DOG :public IClient
	{
		int a{ 0 };

	public:
		DOG(int a, int b) :a(a + b)
		{
		}
		void ClientFun() override
		{
			cout << "DOG called a : " << a << '\n';
		}
	};


	int main()
	{
		CAT cat(111, 222);
		DOG dog(10, 20);

		VendorFun(&cat);
		VendorFun(&dog);

		return 0;
	}
}