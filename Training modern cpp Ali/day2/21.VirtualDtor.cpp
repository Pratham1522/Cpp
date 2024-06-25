#include<iostream>
using namespace std;
#define line(msg) cout<<"________________"#msg"______________________\n"

class CA
{
public:
	static void* operator new(size_t size)
	{
		cout << "CA::operator new\n";
		return malloc(size);
	}
	static void operator delete(void *pv)
	{
		cout << "CA::operator delete\n";
		free(pv);
	}
	CA()
	{
		cout << "CA Ctor\n";
	}
	virtual ~CA()
	{
		cout << "CA D-tor\n";
	}
};

class CB:public CA
{
public:
	CB()
	{
		cout << "CB Ctor\n";
	}
	static void* operator new(size_t size)
	{
		cout << "CB::operator new\n";
		return malloc(size);
	}
	static void operator delete(void* pv)
	{
		cout << "CB::operator delete\n";
		free(pv);
	}
	~CB()
	{
		cout << "CB D-tor\n";
	}
};

int main()
{
	CA* pt = new CB();
	line();
	delete pt;

	return 0;
}
//vtable is static array of function pointer
//this pointer is not polymorphic in constructor and destructor
//object slicing : object only know his partition, not other object area