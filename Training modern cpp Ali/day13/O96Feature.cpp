#include<iostream>
#include<string>
using namespace std;

namespace nm96
{
	struct S {
		int n{ 100 };
		std::string s{ "sachin" };
		float d{ 1.2f };
	};

	template<int index>
	auto getVal(const S& s)
	{
		if constexpr (0 == index)
			return s.n;
		else if constexpr (1 == index)
			return s.s;
		else
			return s.d;

	}

	int main()
	{
		S s1;
		int x = getVal<0>(s1);
		string y = getVal<1>(s1);
		float z = getVal<2>(s1);
		cout << x << '\t' << y << '\t' << z << '\n';
		return 0;
	}
}