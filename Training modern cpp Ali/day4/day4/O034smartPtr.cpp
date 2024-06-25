#include<iostream>
using namespace std;
#define line(msg) cout<<"________________"#msg"______________________\n"

namespace nm54
{
	class CA
	{
	public:
		void fun()
		{
			cout << "Apple\n";
		}
	};

	class Smart_Ptr
	{
		CA* pt;
	public:
		Smart_Ptr(CA* pt = NULL) :pt(pt)
		{
		}
		void fun()
		{
			cout << "Orange\n";
		}
		CA* operator->()
		{
			return pt;
		}
	};

	int main()
	{
		Smart_Ptr* sm = new Smart_Ptr(new CA());
		sm->fun();
		(*sm)->fun();
		return 0;
	}

}
