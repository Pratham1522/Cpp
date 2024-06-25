
## If constexpr
- allows conditional compilation based on constant expressions evaluated at compile time. 
```cpp
template<int index>
void GetMe()
{
	cout << "Apple\n";
	if constexpr (0 == index)
	{
		cout << "Bhindi\n";
	}
	else if constexpr (1 == index)
	{
		cout << "Palak\n";
	}
	else
	{
		cout << "Bottle Guord\n";
	}
	cout << "Orange\n";
}

int main()
{
	GetMe<0>();
	GetMe<1>();
	GetMe<2>();

	return 0;
}
```
