#include<iostream>
using namespace std;
#define line(msg) cout<<"________________"#msg"______________________\n"

namespace nm32
{
	//vedanth kakade
	class CA
	{
		bool isOnHeap;
		static bool globalHeap;
		static int count;
	public:
		CA() :isOnHeap(globalHeap)
		{
			count--;
			if (count <= 0)
			{
				cout << "Ctor\n";
				globalHeap = false;
			}
		}
		static void* operator new(size_t size)
		{
			count = 1;
			cout << "Operator new\n";
			globalHeap = true;
			return malloc(size);
		}
		static void* operator new[](size_t size)
		{
			count = size / sizeof(CA);
			cout << "Operator new[]\n";
			globalHeap = true;
			return malloc(size);
		}
			static void operator delete(void* pv)
		{
			cout << "operator delete\n";
			free(pv);
		}
		static void operator delete[](void* pv)
		{
			cout << "operator delete[]\n";
			free(pv);
		}

			void Location()
		{
			if (true == isOnHeap)
			{
				cout << "I am ON heap\n";
			}
			else if (false == isOnHeap)
			{
				cout << "I am (NOT ON) heap\n";
			}
		}
		~CA()
		{
			cout << "D=tor\n";
		}
	};
	bool CA::globalHeap = false;
	int CA::count = 0;
	int main()
	{
		CA obj1;
		line();
		CA* obj2 = new CA();
		line();
		CA obj3;
		line();
		CA* obj4 = new CA();
		line();
		CA* obj5 = new CA[5];
		line();
		line(NotOnHeap);
		obj1.Location();
		obj3.Location();
		line(On_Heap);
		obj2->Location();
		obj4->Location();
		line(On_Heap);
		for (size_t i = 0; i < 5; i++)
		{
			(obj5 + i)->Location();
		}
		line();
		delete obj2;
		line();
		delete obj4;
		line();
		delete[] obj5;
		line();

		return 0;
	}
}