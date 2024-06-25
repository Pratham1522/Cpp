#include<iostream>
using namespace std;
#define line(msg) cout<<"________________"#msg"______________________\n"

namespace nm10
{
	class CA
	{
	public:
		void f1() { cout << "CA::f1\n"; }
		virtual void f2() { cout << "CA::f2\n"; }
		static void f3() { cout << "CA::f3\n"; }
	};

	int main()
	{
		CA obj;
		CA* objPtr = &obj;
		CA& objRef = obj;    // no memory allocated just a alias.
		CA::f3(); // CA::f3
		// obj.f3();// CA::f3 //dont use this
		line();
		obj.f1();//CA::f1
		obj.f2();//CA::f2
		line();
		objPtr->f1();// CA::f1
		objRef.f1();//CA::f1
		line();
		objPtr->f2();//objPtr->vptr->vtable[0]();
		/*
			mov	eax, DWORD PTR _objPtr$[ebp]
			mov	edx, DWORD PTR [eax]
			mov	esi, esp
			mov	ecx, DWORD PTR _objPtr$[ebp]
			mov	eax, DWORD PTR [edx]
			call	eax
			cmp	esi, esp
			call	__RTC_CheckEsp
		*/
		objRef.f2();//objRef.vptr->vtable[0]();
		/*
			mov	eax, DWORD PTR _objRef$[ebp]
			mov	edx, DWORD PTR [eax]
			mov	esi, esp
			mov	ecx, DWORD PTR _objRef$[ebp]
			mov	eax, DWORD PTR [edx]
			call	eax
			cmp	esi, esp
			call	__RTC_CheckEsp
		*/
		line();
		return 0;
	}
}
