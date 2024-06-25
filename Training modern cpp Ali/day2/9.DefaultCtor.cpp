/*
1.default ctor
2.conversion ctor
3.explicit ctor
4.parameter ctor
5.copy ctor

modern c++
6.move
7.forward ctor
8.init ctor
9.ctor delegation
*/

#include<iostream>
using std::cout;
using std::cin;
#define line(msg) cout<<"------------*"#msg"*--------------\n";

class Animal
	{
	public:
		Animal()
		{
            cout<<"Animal C-tor\n";
		}
		void fun()
		{
            cout<<"Fun C-tor\n";
		}
        ~Animal()
		{
            cout<<"Animal D-tor\n";
		}
	};

	class Tiger :public Animal
	{
	public:
		Tiger()//Animal::Animal
		{
            cout<<"Tiger C-tor\n";
		}
        ~Tiger()
		{
            cout<<"Tiger D-tor\n";
		}//Animal::~Animal        
	};

	int main1()
	{
		Tiger tiger;//Tiger::Tiger
		return 0;
	}


	class Eye
	{
	public:
		Eye()
		{
            cout<<"Eye  C-tor\n";
		}
		void fun()
		{
		}
        ~Eye()
		{
            cout<<"Eye  D-tor\n";
		}
	};

	class Lion:public Animal
	{
		Eye eyes;
	public:
		Lion() //Animal::Animal , Eye::Eye
		{
            cout<<"Lion C-tor\n";
		}
        ~Lion()
		{
            cout<<"Lion C-tor\n";
		}
	};

	int main()
	{
		Lion lion;//Lion::Lion
		return 0;
	}
    //base ctor,contained ctor,obj ctor
	// default constructors are generated/synthesisd by compiler when needed.
	// base: animal ,derived : tiger , main : tiger obj, then tiger const call first, and tiger constructor prolog calls animal constructor if present.
    //eg: when base class animal has constructor and derived class tiger have no constructor then compiler creates a tiger constructor to call animal constructor
    // constructor call happens if it is present
    //constructor is just a normal function ,its just that it is called by compiler whenever needed.
    //normal global and class function is also same, just class functions have class name associated with it.
    // conatined object is also called from constructor prolog

    //constructor is for resource allocation not initialization
    //base class l to r , containment t to bottom
