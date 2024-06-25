#include<iostream>
using namespace std;
#define line(msg) cout<<"________________"#msg"______________________\n"

//variadic templates.
namespace nm43
{
	void printMe()
	{
		cout << '\n';
	}
	//function specialization
	template<typename T>
	void printMe(T par)
	{
		cout << par << " :  end\n";
	}
	template<typename T1,typename T2>
	void printMe(T1 par,T2 par2)
	{
		cout << par <<" -> "<<par2 << " :  end\n";
	}
	//template pack type
	template<typename T1, typename... T> //Template packing
	void printMe(T1 p, T... par)//pack recieved
	{
		cout << p << '\t';
		printMe(par...);//unpacking
	}

	int main()
	{
		printMe(10, 20, 30, 50);
		printMe(100, 'c', 3.141, 2.12f);
		printMe(100);
		printMe();
		return 0;
	}
}
