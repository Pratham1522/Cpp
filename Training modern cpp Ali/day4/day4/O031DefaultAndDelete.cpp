#include<iostream>
using namespace std;
#define line(msg) cout<<"________________"#msg"______________________\n"

namespace nm31
{
	class CA
	{
	public:
		static void* operator new(size_t) = delete;
		static void* operator new[](size_t) = delete;
		static void operator delete(void*) = delete;
		static void operator delete[](void*) = delete;

		CA() = default;
		~CA() = default;

		CA(const CA&) = delete;
		CA& operator=(const CA&) = delete;

		void AddFun(double x, double y)
		{
		}

		void AddFun(int, int) = delete;

		void SubFun(double x, double y)
		{
		}

		template<typename T>
		void SubFun(T, T) = delete;
	};

	int main()
	{
		CA obj1;
		//CA obj2(obj1);  //error copy deleted.
		CA obj3;
		//obj1 = obj3;  //error 
		//CA* obj4 = new CA();  //error
		//delete obj4;   //error

		//CA* obj5 = new CA[5];   //error
		//delete [] obj5;

		//obj1.AddFun(10, 20);  //error
		obj1.AddFun(1.0, 2.0);
		obj1.AddFun(1.0f, 2.0f);

		//obj1.SubFun(10, 20);
		obj1.SubFun(1.0, 2.0);
		//obj1.SubFun(1.0f, 2.0f);
		return 0;
	}
}
