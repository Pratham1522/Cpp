#include<iostream>
using namespace std;

namespace nm95
{
	struct MyClass1
	{
		static const int sValue;
	};

	inline int const MyClass1::sValue = 777;


	struct MyClass2
	{
		inline static const int sValue = 777;
	};

	inline int g_x = 42;
	int  main()
	{
		std::cout << MyClass2::sValue << std::endl;
		return 0;
	}
}