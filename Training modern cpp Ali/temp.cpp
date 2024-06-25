#include <iostream>
using std::cout;

class Cont
{
	public:
		Cont()
		{
			cout << "Cont C-tor" << '\n';
		}
		Cont(const Cont&)
		{
			cout << "Cont Copy C-tor" << '\n';
		}
		Cont& operator=(const Cont& obj)
		{
			cout << "Cont Assignment operator" << '\n';
			return *this;
		}
		static void* operator new (size_t size)  // new and delete
		{
			return malloc(size);
		}
		static void operator delete (void *pv)
		{
			free(pv);
		}
		~Cont()
		{
			cout << "Cont D-tor" << '\n';
		}

};
class Base
{
	public:
		Base()
		{
			cout << "Base Default C-tor" << '\n';
		}
		Base(const Base& obj)
		{
			cout << "Base Copy C-tor" << '\n';
		}
		Base& operator=(const Base& obj)
		{
			cout << "Base Assignment Operator" << '\n';
			return *this;
		}
		static void* operator new ( size_t size)
		{
			return malloc(size);
		}
		static void operator delete (void *pv)
		{
			free(pv);
		}
		~Base()
		{
			cout << "Base D-tor" << '\n';
		}
};

class Derived:public Base
{
	private:
		Cont contObj;
	public:
		Derived()
		{
			cout << "Derived C-tor" << '\n';
		}
		Derived(const Derived& obj)
		{
			cout << "Derived Copy C-tor" << '\n';
		}
		Derived& operator=(const Derived& obj)
		{
			cout << "Derived Assign operator" << '\n';
			return *this;
		}
		static void* operator new (size_t size)
		{
			cout << "Derived Operator New Called \n";
			return malloc(size);
		}
		static void operator delete (void *pv)
		{
			cout << "Derived Operator Delete called";
			free(pv);
		}
		~Derived()
		{
			cout << "Derived D-tor" << '\n';
		}
};

class Account
{
	protected:
		virtual void actualDebit(int Accid, int amount) = 0;

	public:
		void Debit(int Accid, int amount)
		{
			std::cout << "Open DB" << '\n';
			actualDebit(Accid,amount);
			std::cout << "Close DB" << '\n';
		}
};
class SavingAccount : public Account
{
	protected:
		void actualDebit(int Accid, int amount)
		{
			cout << "Debit Savings" << '\n' ;
		}
};
class CurrentAccount : public Account
{
	protected:
		void actualDebit(int Accid, int amount)
		{
			cout << "Debit Current" << '\n' ;
		}
};

int main()
{
	SavingAccount sa;
	sa.Debit(100,1000);
	CurrentAccount ca;
	ca.Debit(101,1000);
	return 0;
}
