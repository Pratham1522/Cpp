#include<iostream>
#include<functional>
#include<string>
#include<vector>
using namespace std;
#define line(msg) cout<<"___________________"#msg"____________________\n"

auto shubam = [](int x, int y) {return x + y; };

template<typename T>
T mano(T x, T y) { return x + y; }

auto aabhash = [](auto x, auto y) {return x + y; };


template<typename T>
ostream& operator<<(ostream& os, vector<T>& vec)
{
	for (auto rng:vec)
	{
		os << rng << '\t';
	}
	os << '\n';
	return os;
}


//
//template<typename... T>
//ostream& operator<<(ostream& os, tuple<T...>const & tup)
//{
//	std::apply([&os](T const&... tupArgs) {
//		os << "[ ";
//		((os << tupArgs << '\t'), ...);
//		}, tup);
//	os << " ]\n";
//	return os;
//}



template<typename... T>
ostream& operator<<(ostream& os, tuple<T...>const& tup)
{
	std::apply([&os](T const&... tupArgs) {
		os << "[ ";
		size_t i{ 0 };
		((os << tupArgs << (++i != sizeof...(T) ? "\t" : "")), ...);
		}, tup);
	os << " ]\n";
	return os;
}
int main()
{
	
	cout << "result1 : " << std::apply(shubam, make_tuple(10, 20)) << '\n';
	cout << "result2 : " << std::apply(aabhash, make_tuple(100, 200)) << '\n';
	cout << "result3 : " << std::apply(shubam, std::pair(10, 20)) << '\n';
	cout << "result4 : " << std::apply(aabhash, std::pair(100, 200)) << '\n';

	//error : cant deduce function types
	//cout << "result5 : " << std::apply(mano, make_tuple(10, 20)) << '\n';

	tuple vishal(100, "shagun", 1.0f, 3.14159, 'c');
	cout << vishal << '\n';

	return 0;
}
