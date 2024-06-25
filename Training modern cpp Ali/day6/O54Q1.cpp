#include<iostream>

class CA
{
public:

	static void* operator new(size_t size)
	{
		std::cout << "CA::operator new\n";
		return malloc(size);
	}

	static void operator delete(void* pv)
	{
		std::cout << "CA::operator delete\n";
		free(pv);
	}

	CA()
	{
		std::cout << "CA::Constructor\n";
		throw 200;
	}

	~CA() noexcept
	{
		std::cout << "CA::Destructor\n";
	}
};

int main()
{
	try
	{
		CA* ca = new CA();
	}
	catch (int exp)
	{
		std::cout << "Exp : " << exp << '\n';
	}
	return 0;
}