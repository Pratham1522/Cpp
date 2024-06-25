#include<iostream>
#include<string>
#include<mutex>
using namespace std;

namespace nm97
{
	template<typename A, typename B>
	struct CA {
		CA(A a, B b)
		{
			cout << "a = [ " << typeid(a).name() << " ]\n";
			cout << "b = [ " << typeid(b).name() << " ]\n";
		}
		A a; B b;
	};

	template<typename T> struct S { S(T) { cout << "S T = [ " << typeid(T).name() << " ]\n"; } };

	int main()
	{
		CA<int, double> obj1(111, 12.34);
		CA obj2(111, 12.34);
		cout << "______________________________\n";
		S s(900);
		mutex mute;
		mute.lock();
		mute.unlock();

		lock_guard loc1(mute);//lock_guard<mutex> loc(mute);
		return 0;
	}
}