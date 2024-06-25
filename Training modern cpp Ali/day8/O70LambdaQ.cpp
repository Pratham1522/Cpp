#include<iostream>
using namespace std;
#define line(msg) cout<<"____________________"#msg"______________________\n"

namespace nm70
{
	template<typename T>
	void VendorFun(T obj)
	{
		cout << "vendor job started\n";
		int res = obj(25);
		cout << "vendor job completed result : " << res << '\n';
		line();
	}

	//-------------------------

	int main()
	{
		int i = 100;
		int j = 200;
		//auto fnc = [](int par) {cout << "\t\t\tI am from lambda par : " << par << "%\n"; return par * 30; };
		auto fnc = [=](int par) mutable ->int {cout << "\t\t\tI am from lambda par : " << par << "%\n"; return par * 30; };
		VendorFun(fnc);
		return 0;
	}
}
