#include<iostream>
using namespace std;
#define line(msg) cout<<"____________________"#msg"______________________\n"

namespace nm58
{
	//typedef void (*FPTR)();
	using FPTR = void (*)();//c++11 onwards
	//void VendorFun(void (*fp)())
	void VendorFun(FPTR fp)
	{
		cout << "vendor job started\n";
		//(*fp)();//client code
		fp();
		cout << "vendor job completed\n";
		line();
	}


	//--------------------------------
	void ClientFun()
	{
		cout << "Hi I am from client\n";
	}

	void Fun()
	{
		cout << "Haaaaaaaaaaaaaaa\n";
	}
	void Fun1()
	{
		cout << "Heeeeeeeeeeeeeee\n";
	}

	int main()
	{
		//void (*fp1)() = &ClientFun;
		//void (*fp2)() = ClientFun;
		FPTR fp1 = ClientFun;
		FPTR fp2 = Fun;
		VendorFun(fp1);
		VendorFun(fp2);
		VendorFun(Fun1);
		VendorFun(&Fun1);

		return 0;
	}
}