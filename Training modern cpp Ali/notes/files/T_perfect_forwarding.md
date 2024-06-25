
## Perfect Forwarding
- Perfect forwarding in C++ refers to the ability to preserve the value category (lvalue or rvalue) and the constness of function arguments when forwarding them to another function. It allows you to forward arguments to another function without losing their original characteristics.

- if recieving in move object , always use perfect forward.
```cpp
auto Sum()
	{
		return 0;
	}

	template<typename T1, typename... T>
	auto Sum(T1 p, T... par)//pack recieved
	{
		return p + Sum(par...);//unpacking
	}

	class CA
	{
	public:
		CA()
		{
			cout << "Default \n";
		}
		CA(CA&& par) noexcept
		{
			cout << "Move\n";
		}
	};

	void f1(int a)
	{
		cout << "f1(int) a=" << a << '\n';
	}

	void f1(int a, int b)
	{
		cout << "f1(int,int) a=" << a << " ,  b=" << b << '\n';
	}

	void f1(int a, int b, CA&& par)
	{
		cout << "f1(int,int,CA) a=" << a << " ,  b=" << b << '\n';
	}

	template<typename... PCK>
	void Wrapper(PCK... pck)
	{
		line();
		// f1(pck...);  //error bcoz pck by default has CA not CA&&
		f1(std::forward<PCK>(pck)...);
	}

	int main()
	{
		CA obj1;
		//Wrapper(10);
		//Wrapper(10,20);
		Wrapper(10, 20, std::move(obj1));
		return 0;
	}
```
