#include<iostream>
#include<tuple>
#include<set>
#include<map>
using namespace std;

namespace nm94::sachin::rahul //nested namespace c++17
{
	enum class Color;//forward declared
	enum Signal //unscoped
	{
		red,
		yellow,
		green
	};
	enum class Color //scoped
	{
		pink,
		blue,
		black
	};

	enum class Mood :int8_t
	{
		hungry,
		dipress,
		happy//,
		//blue
	};

	int main()
	{

		switch (Signal sig = Signal::red; sig)
		{
		case red:
			break;
		case yellow:
			break;
		case green:
			break;
		default:
			break;
		}

		Color col = Color::pink;
		switch (col)
		{
		case Color::pink:
			break;
		case Color::blue:
			break;
		case Color::black:
			break;
		default:
			break;
		}
		return 0;
	}
}