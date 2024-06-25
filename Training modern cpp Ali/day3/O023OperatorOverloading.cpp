#include<iostream>
using namespace std;
#define line(msg) cout<<"________________"#msg"______________________\n"


	class CA
	{
		int x;
		int y;
	public:
		CA(int p1, int p2) :x(p1), y(p2) //param const
		{
            cout<<"CA param constructor \n";
			cout << "this : [ " << this << " ]\n";
			cout << "x    : [ " << &x << " ]\n";
			cout << "y    : [ " << &y << " ]\n";
		}
		void* operator&()     //refernce operator overloading
		{
			return &y;
		}
	};
	int main()
	{
		CA obj(10, 20);
		line();
		cout << "&obj : [ " << &obj << " ]\n";
		cout << "addressof(obj) : [ " << addressof(obj) << " ]\n";

		return 0;
	}

    //addressof(var) : return memory address.
