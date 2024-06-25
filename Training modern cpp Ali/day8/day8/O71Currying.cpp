#include<iostream>
using namespace std;
#define line(msg) cout<<"____________________"#msg"______________________\n"

namespace nm71
{
	void f3()
	{
	}
	using FPTR = void(*)();
	FPTR f2()
	{
		return f3;
	}
	using FPTR1 = FPTR(*)();
	FPTR1 f1()
	{
		return f2;
	}

	auto Greet(string name)//f1
	{
		return [name](string sep) { //f2
			return [name, sep](string msg) { //f3
				cout << msg << sep << name << '\n';
			};
		};
	}

	//-------------------------

	int main1()
	{
		Greet("Rajinikanth  ")("--->")("Happy Diwali");
		Greet("Rahul Dravid ")("--->")("Happy Diwali");
		Greet("Sachin       ")("--->")("Happy Diwali");
		line();

		Greet("VVS          ")("--->")("Happy Deepavali");
		Greet("Chiranjeevi  ")("--->")("Happy Deepavali");
		Greet("NTR          ")("--->")("Happy Deepavali");
		line();

		Greet("Karthick     ")("--->")("Happy Deebawali");
		Greet("KSK          ")("--->")("Happy Deebawali");
		Greet("Ravi Aswin   ")("--->")("Happy Deebawali");

		return 0;
	}


	int main()
	{
		auto fn1 = Greet("Rajinikanth  ");
		auto fn2 = fn1("---->");

		fn2("Happy Diwali");
		fn2("Happy New year");
		fn2("Happy Onam");
		fn2("Happy Pongal");
		fn2("Happy Sankranthi");
		return 0;
	}
}