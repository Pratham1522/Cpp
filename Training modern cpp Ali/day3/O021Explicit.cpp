#include<iostream>
using namespace std;
#define line(msg) cout<<"________________"#msg"______________________\n"


	class CA
	{
		int x;
		int y;
	public:
		explicit CA(int x) :x(x), y(x)
		{
			cout << "one param ctor\n";
		}
		explicit CA(int x, int y) :x(x), y(x)
		{
			cout << "two param ctor\n";
		}
		void Disp()
		{
			cout << "x=" << x << " y="<<y<< '\n';
		}
		CA& operator=(const CA& par)
		{
			cout << "Assignment\n";
			this->x = par.x;
			return *this;
		}
        CA& operator=(int value) 
        {
            cout << "Assignment from int\n";
            this->x = value;
            return *this;
        }
	};

	void f1(CA par)
	{
		cout << "Apple\n";
	}

	
	int main1()
	{
		CA obj1(100);//construction
		// obj1.Disp();  // one param const
		// line();
		// CA obj2 = 200;//conversion  //error is one para constructor is explicit.
		CA obj2 = CA(200);
		obj2.Disp();
		line();
		// obj1 = 300;//conversion and then assignment,need '=' operator overload with int.
		// obj1.Disp();
		line();
		// f1(10);//error on explicit ctor
		f1(CA(100)); //why this works
		return 0;
	}
	

	int main()
	{
		CA obj1(100);//construction
		// line();
		// CA obj2=100; //error due to explicit
		// line();
		// CA obj3(100,200);//construction
		// line();
		// CA obj4 = (111, 222); //error explicit
		// line();
		// obj1 = 234;
		//line();
		// obj1 = (22, 33);
		line(BraceInit);
		// int x{ 10 };
        // cout<<"Brace "<<x<<"\n";
		//int y = { 20 };
		// CA obj5{ 10 };//construction , copy list initialization
		line();
		// CA obj6 = { 10 };//conversion                     #error
		//line();
		// CA obj7 { 10,10 };//construction
		//line();
		// CA obj8 = { 11,22 };//conversion                   #error
		//line();
		obj1 = { 100 };//conversion
		//line();
		// obj1 = { 1,2 };//conversion                        #error
		//line();
		return 0;
	}
