#include<iostream>
using namespace std;
#define line(m) cout<<"___________________________\n"

namespace nm51
{
	class CA
	{
		int size{ 0 };
		int* arr{ nullptr };
	public:
		CA(int val) :CA{ val }
		{
			cout << "One Param\n";
		}
		CA(int val1, int val2) :CA{ val1,val2 }
		{
			cout << "Two Param\n";
		}
		CA(std::initializer_list<int> lst) :size(lst.size()), arr(new int[size])
		{
			cout << "Init\n";
			unsigned int index = 0;
			for (auto& rng : lst)//range loop c++11 onwards
			{
				arr[index++] = rng;
			}
		}
		~CA() noexcept
		{
			delete[] arr;
		}

		friend ostream& operator<<(ostream& os, CA& par)
		{
			for (size_t i = 0; i < par.size; i++)
			{
				os << par.arr[i] << '\t';
			}
			os << '\n';
			return os;
		}
	};


	int main()
	{
		CA obj1{ 3 };
		CA obj11(90.87);
		line();
		CA obj2{ 11,22 };
		line();
		CA obj3 = { 111 };
		line();
		CA obj4 = { 1111,2222 };
		line();
		CA obj5(11111);
		line();
		CA obj6 = 999;
		line();
		CA obj7(123, 456);
		line();
		CA obj8{ 1, 2, 3, 4, 5, 6, 7, 8, 9 };
		line();
		cout << obj1 << obj2 << obj3 << obj4 << obj5 << obj6 << obj7 << obj8;
		line();
		return 0;
	}
}