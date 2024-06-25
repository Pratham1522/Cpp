#include<iostream>
using namespace std;
#define line(msg) cout<<"________________"#msg"______________________\n"


	class CA
	{
		int* a;
	public:
		CA(int val) :a(new int(val))
		{
			cout << this << " : CA Ctor a : [ " << a << " ]\n";
		}
		//ownership transfer
		CA(const CA& par) :a(par.a)
		{
			CA& caRef = const_cast<CA&>(par); //allow modification in const obj.
			caRef.a = NULL;
			cout << this << " : CA Shallow Copy a : [ " << a << " ]\n";
		}

		/*CA& operator=(const CA& par)
		{
			if (this == &par)
				return *this;
			cout << this << " : CA Shallow Assignment\n";
			this->CA::~CA();
			this->CA::CA(par);//works only in VC++
			return *this;
		}*/

		CA& operator=(const CA& par)
		{
			if (this == &par)//if same obj.
				return *this;
			cout << this << " : CA Shallow Assignment\n";
			//copy and swap
			CA temp(par);
			this->Swap(temp);
			return *this;
		}
		void Swap(CA& tmp)
		{
			std::swap(this->a, tmp.a);
		}
		~CA()
		{
			cout << this << " : CA D-tor a : [ " << a << " ]\n";
			delete a;
		}
	};

	int main()
	{
		CA obj1(100);
		CA obj2(200);// obj1;

		line();
		line();
		obj1 = obj2;
		line();
		return 0;
	}

