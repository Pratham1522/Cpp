#include<iostream>
using std::cout;
#define line(m) cout<<"___________________________\n"

namespace nm49
{
	int main1()
	{
		int x{ 10 };
		int y{ 20 };
		//int* pt{ &x };//normal pointer
		//const int* pt{ &x };//pointer to a constant
		// int const * pt{ &x };//pointer to a constant
		//int  * const pt{ &x };// constant pointer
		//const int  * const pt{ &x };// constant pointer to a constant
		int const* const pt{ &x };// constant pointer to a constant

		//*pt=999; //l1
		//pt = &y; //l2
		cout << "&x : " << &x << '\n';
		cout << "pt : " << pt << '\n';
		cout << "&y : " << &y << '\n';
		cout << "x  : " << x << '\n';
		cout << "y  : " << y << '\n';

		return 0;
	}


	void f1(const int* pt)
	{
		int* p = const_cast<int*>(pt);
		*p = 999;
		cout << "*p=" << *p << '\n';
	}

	int main()
	{
		int x = 10;
		const int y = 20;

		f1(&x);
		f1(&y);

		cout << "x  : " << x << '\n';
		cout << "y  : " << y << '\n';
		return 0;
	}
}
