#include<iostream>
using namespace std;
#define line(msg) cout<<"________________"#msg"______________________\n"


	//reference counting
	class CA
	{
		int* a;
		int* count;
	public:
		CA(int val) :a(new int(val)), count(new int(1))
		{
			cout << this << " : CA Ctor a : [ " << a << " ]\n";
		}
		CA(const CA& par) :a(par.a), count(par.count)
		{
			++(*count);
			cout << this << " : CA Shallow Copy a : [ " << a << " ]\n";
		}
		CA& operator=(const CA& par)
		{
			if (this == &par)
				return *this;
			cout << this << " : CA Shallow Assignment\n";
			CA temp(par);
			this->Swap(temp);
			return *this;
		}
		void Swap(CA& tmp)
		{
			std::swap(this->a, tmp.a);
			std::swap(this->count, tmp.count);
		}
		~CA()
		{
			cout << this << " : CA D-tor a : [ " << a << " ]\n";
			--(*count);
			if ((*count) == 0)
			{
				delete a;
				delete count;
				cout << this << " : CA Releases a : [ " << a << " ]\n";
			}
		}
	};

	int main()
	{
		CA obj1(100);
		CA obj1_2(obj1);
		CA obj1_3(obj1);

		CA obj2(200);
		CA obj2_2(obj2);
		CA obj2_3(obj2);

		line();
		line();
		obj1 = obj2;
		// obj1_2 = obj2;
		// obj1_3 = obj2;
		line(Before);
		return 0;
	}

