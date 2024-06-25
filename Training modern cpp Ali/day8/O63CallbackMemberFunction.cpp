#include<iostream>
using namespace std;
#define line(msg) cout<<"____________________"#msg"______________________\n"

namespace nm63
{
	class CVendor
	{
		int x{ 0 };
		int y{ 0 };
	public:
		CVendor(int x, int y) :x(x), y(y)
		{
		}
		void f1()
		{
			cout << "CVendor f1 called x : " << x << " y : " << y << '\n';
		}
		void f2()
		{
			cout << "CVendor f2 called x : " << x << " y : " << y << '\n';
		}
	};

	using FPTR = void(CVendor::*)();
	void VendorFun(CVendor& cv, FPTR fp)
	{
		cout << "vendor job started\n";
		(cv.*fp)();//member function callback
		cout << "vendor job completed\n";
		line();
	}
	//--------------------------------
	int main()
	{
		CVendor cv1(111, 222);
		CVendor cv2(100, 200);
		FPTR fp1 = &CVendor::f1;
		FPTR fp2 = &CVendor::f2;
		VendorFun(cv1, fp1);
		VendorFun(cv1, fp2);
		VendorFun(cv2, fp1);
		VendorFun(cv2, fp2);
		return 0;
	}

}