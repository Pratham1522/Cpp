#include<iostream>
using namespace std;
#define line(msg) cout<<"________________"#msg"______________________\n"


	class CA
	{
	public:
		CA()
		{
			cout<<"CA\n";
			Apple();//CA::Apple
		}
		void DoJob()
		{
			Apple();//this->vptr->vtable[0]()
			/*
				mov	eax, DWORD PTR _this$[ebp]
				mov	edx, DWORD PTR [eax]
				mov	esi, esp
				mov	ecx, DWORD PTR _this$[ebp]
				mov	eax, DWORD PTR [edx]
				call	eax
				cmp	esi, esp
				call	__RTC_CheckEsp
			*/
		}
		virtual void Apple()
		{
			cout << "CA::Apple Ooty\n";
		}
		~CA()
		{
			cout<<"~CA\n";
			Apple();//CA::Apple
		}
	};

	class CB :public CA
	{
	public:
		CB()
		{
			cout<<"CB\n";
		}
		void Apple() override
		{
			cout << "CB::Apple Shimla\n";
		}
		~CB()
		{
			cout<<"~CB\n";
		}
	};

	int main()
	{
		CB obj1;
		obj1.DoJob();


		return 0;
	}
