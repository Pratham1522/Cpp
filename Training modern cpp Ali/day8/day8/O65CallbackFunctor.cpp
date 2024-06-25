#include<iostream>
using namespace std;
#define line(msg) cout<<"____________________"#msg"______________________\n"

namespace nm65
{

	template<typename T>
	void VendorFun(T obj)
	{
		cout << "vendor job started T [ " << typeid(T).name() << " ]\n";
		obj();//callback
		cout << "vendor job completed\n";
		line();
	}

	//-------------------------

	void ClientFun(int p1, int p2)
	{
		cout << "ClientFun called p1 : " << p1 << " p2 : " << p2 << '\n';
	}

	class Shubam
	{

	public:
		using FPTR = void(*)(int, int);
		Shubam(int i, int j, FPTR fp) :i(i), j(j), fp(fp)
		{
		}
		void operator()() const //inspector
		{
			fp(i, j);
		}
	private:
		int i;
		int j;
		FPTR fp;
	};
	int main()
	{
		int i = 100;
		int j = 200;
		Shubam::FPTR fp = &ClientFun;
		Shubam shubam(i, j, fp);
		VendorFun(shubam);
		return 0;
	}

}