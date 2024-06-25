## UDL -> User defined literals
```cpp
constexpr long double operator "" _rad(long double deg)
{
	return 3.14159 / 180.0 * deg;
}

int main()
{
	constexpr long double angle = 90.0_rad;

	cout << "Angle : " << angle << '\n';
	return 0;
}
```
