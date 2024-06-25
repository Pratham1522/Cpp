#include<iostream>
using namespace std;
#define line(msg) cout<<"____________________"#msg"______________________\n"

namespace nm66
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

	int main()
	{
		int i = 100;
		int j = 200;
		//lambda expression 
		//auto f1 = []() {cout << "I am from lambda\n"; };//inspector () operator
		//auto f1 = []() mutable {cout << "I am from lambda\n"; };//mutator () operator
		//auto f1 = [i]() { /*i += 100;*/ cout << "I am from lambda\n"; };//inspector () operator
		//auto f1 = [i]() {  cout << "I am from lambda i : " << i << '\n'; };//capture i by value inspector () operator
		//auto f1 = [i,j]() {  cout << "I am from lambda i : " << i <<",j : "<<j << '\n'; };//capture i by value inspector () operator
		//auto f1 = [i, j]() mutable { i += 100; j += 200; cout << "I am from lambda i : " << i << ",j : " << j << '\n'; };//capture i,j by value mutator () operator
		//auto f1 = [=]() mutable { i += 100; j += 200; cout << "I am from lambda i : " << i << ",j : " << j << '\n'; };//capture all by value mutator () operator
		//auto f1 = [=]()  {  cout << "I am from lambda i : " << i << ",j : " << j << '\n'; };//capture all by value inspector () operator
		//auto f1 = [&i, &j]()  { i += 100; j += 200; cout << "I am from lambda i : " << i << ",j : " << j << '\n'; };//capture i,j by reference inspector () operator
		//auto f1 = [&]()  { i += 100; j += 200; cout << "I am from lambda i : " << i << ",j : " << j << '\n'; };//capture all by reference inspector () operator
		//auto f1 = [&,j]()  { i += 100;  cout << "I am from lambda i : " << i << ",j : " << j << '\n'; };
		auto f1 = [=, &i]() { i += 100;  cout << "I am from lambda i : " << i << ",j : " << j << '\n'; };

		VendorFun(f1);
		return 0;
	}
}
