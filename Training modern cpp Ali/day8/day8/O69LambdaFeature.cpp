#include<iostream>
using namespace std;
#define line(msg) cout<<"____________________"#msg"______________________\n"

namespace nm69
{
	using FPTR = void(*)(int);
	void VendorFun(FPTR obj)
	{
		cout << "vendor job started\n";
		obj(25);
		cout << "vendor job step 2\n";
		obj(50);
		cout << "vendor job step 3\n";
		obj(75);
		cout << "vendor job step 4\n";
		obj(90);
		cout << "vendor job completed\n";
		obj(100);
		line();
	}

	//-------------------------

	int main()
	{
		int i = 100;
		int j = 200;
		auto fnc = [](int par) {cout << "\t\t\tI am from lambda par : " << par << "%\n"; };
		VendorFun(fnc);
		return 0;
	}

}