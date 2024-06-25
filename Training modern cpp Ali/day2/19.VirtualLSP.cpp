#include<iostream>
using namespace std;
#define line(msg) cout<<"________________"#msg"______________________\n"

/*
1. yagni -> you arn't gonna need it
2. High cohession
3. SRP -> Single Responsibility Priniciple
4. Kiss -> keep it simple and stupid
5. Dry/Die/Wet/Oaoo -> dont repeat yourself/duplication is evil/We Enjoy typing/Once and only once
6. LSP -> Liskov's Substitution Principle
*/

namespace nm18
{
	//interface
	class IX
	{
	public:
		virtual void fx1() = 0;
		virtual void fx2() = 0;
	};

	class CX :public IX
	{
	public:
		void fx1() override
		{
			cout << "CX::fx1\n";
		}

		void fx2() override
		{
			cout << "CX::fx2\n";
		}
	};

	int main()
	{
		CX obj;
		obj.fx1();
		obj.fx2();
		line();
		IX* px = &obj;//LSP
		px->fx1();//px->vptr->vtable[0]();
		px->fx2();//px->vptr->vtable[1]();
		line();
		IX& pxRef = obj;
		pxRef.fx1();//pxRef.vptr->vtable[0]();
		pxRef.fx2();//pxRef.vptr->vtable[0]();
		return 0;
	}
}