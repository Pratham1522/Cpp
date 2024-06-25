#include<iostream>
using namespace std;
#define line(msg) cout<<"________________"#msg"______________________\n"

namespace nm53
{
	class CA
	{
		int x;
	public:
		CA(int x) :x(x)
		{
		}
		void f1()
		{
			cout << "apple x : " << x << '\n';
		}
		void f2()
		{
			cout << "Orange x : " << x << '\n';
		}
	};

	using FPTR = void(CA::*)();
	void Business(FPTR fp, CA* obj)
	{
		cout << "start\n";
		(obj->*fp)();
		cout << "stop\n";
		line();
	}


	int main1()
	{
		CA* ptr1 = new CA(10);
		CA* ptr2 = new CA(100);
		FPTR fp1 = &CA::f1;
		FPTR fp2 = &CA::f2;
		Business(fp1, ptr1);
		Business(fp1, ptr2);
		Business(fp2, ptr1);
		Business(fp2, ptr2);
		return 0;
	}


	class Smart
	{
		CA* pt{ nullptr };
		FPTR fp{ nullptr };
	public:
		Smart(CA* pt = nullptr) :pt(pt)
		{
		}
		CA* operator->()
		{
			return pt;
		}
		CA& operator*()
		{
			return *pt;
		}
		Smart& operator->*(FPTR fp)
		{
			this->fp = fp;
			return *this;
		}
		void operator()()
		{
			(pt->*fp)();
		}
		~Smart()
		{
			delete pt;
		}
	};

	void Business1(FPTR fp, Smart& obj)
	{
		cout << "start\n";
		//(obj->*fp)();

		//Smart& tmp = obj->*fp;
		//tmp();

		Smart& tmp = obj.operator->*(fp);
		tmp.operator()();

		cout << "stop\n";
		line();
	}

	int main()
	{
		Smart ptr1 = new CA(10);
		Smart ptr2 = new CA(100);
		FPTR fp1 = &CA::f1;
		FPTR fp2 = &CA::f2;
		Business1(fp1, ptr1);
		Business1(fp1, ptr2);
		Business1(fp2, ptr1);
		Business1(fp2, ptr2);
		return 0;
	}
}