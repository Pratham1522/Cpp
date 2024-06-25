// accessing internal vptr using pointer.

#include<iostream>
using namespace std;
#define line(msg) cout<<"________________"#msg"______________________\n"

//static : before main ,static gets initialised
// if members is there then first vptr in stack then members.
// vptr points to vtable, and mapping of vptr to vtable happens at constructor prolog expansion.
// namespace nm8
// {
	class CA
	{

	};

	class CB
	{
		//general size of class is 1
	public:
		void fun()
		{
			
		}
	};

	class CC
	//bcz of virtual class size becames 8
	{
	public:
		void fun1()
		{
		}
		virtual void fun2()
		{
			cout << "CC::fun2\n";
		}
	};

	int main1()
	{
		CA obj;
		cout << "sizeof(obj)  : " << sizeof(obj) << '\n';  //1
		CB obj1;
		cout << "sizeof(obj1) : " << sizeof(obj1) << '\n';  //1
		CC obj2;
		cout << "sizeof(obj2) : " << sizeof(obj2) << '\n';  //8

		return 0;
	}

	void f1()
	{
	}
	void f2(int, int)
	{
	}


	int main()
	{
		//typedef void(*FPTR)();
		using FPTR = void(*)();//modern c++
		CC obj2;
		//((void(*)())* (long*)*(long*)&obj2)();
		//step 1 reach the vptr
		long* vptr = (long*)&obj2;
		//step 2 reach the vtable
		long* vtable = (long*)*vptr;
		//step 3 reach the function
		void(*fp)() = (void(*)())vtable[0];
		//FPTR fp=(FPTR)vtable[0];
		//step 4 callback
		//(*fp)();//c-syntax
		fp();//c++ syntax
		return 0;
	}

// }
