#include<iostream>
using namespace std;
#define line(msg) cout<<"________________"#msg"______________________\n"


	class CA
	{
		int x;
		int y;
	public:
		CA(int x, int y) :x(x), y(y)//cosntructor
		{
            cout<<"CA constructor \n";
		}
		explicit operator int()  //used to convert CA to int
		{
			return x + y;
		}
		explicit operator CA* ()  //convert CA to CA*
		{
			return this;
		}
		operator void* ()     //convert CA to void*
		{
			return (void*)this;
		}
	};

	int main()
	{
		CA obj1(1, 2);
		CA obj2(11, 22);
		line();
		// int a = obj1;//conversion operator or casting operator
		line();
		int b = (int)obj2; //(int) is mandatory
        cout<<b<<" : b\n";
		line();
		// CA* pt = obj1;
		CA* pt1 = (CA*)obj1;

		void* p = obj2;
		return 0;
	}
