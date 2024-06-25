#include<iostream>
using namespace std;
#define line(msg) cout<<"____________________"#msg"______________________\n"
namespace nm67
{
	template<typename FN, typename... T>
	void HOF(FN fn, T&&... par)
	{
		cout << "HOF\n";
		fn(std::forward<T>(par)...);
	}

	class CA
	{
	public:
		CA() = default;
		CA(const CA&)
		{
			cout << "CA Copy\n";
		}
		CA(CA&&) noexcept
		{
			cout << "CA move\n";
		}
		~CA() = default;
	};

	void fun(CA&& obj)
	{
	}

	int main()
	{
		CA obj;
		HOF(fun, std::move(obj));
		return 0;
	}
}