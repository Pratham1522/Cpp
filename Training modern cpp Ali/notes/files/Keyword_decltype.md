## decltype keyword
- The decltype keyword allows you to obtain the type of an expression or variable without evaluating it. It's useful in situations where you want to declare a variable with the same type as another expression or variable.
- decltype is a specifier that returns the type of an expression at compile time without actually evaluating the expression.
```cpp
template<typename T1, typename T2>
auto MulFun(T1 x, T2 y)->decltype(x* y)  //trailing deduce : c++11 onwards
{
	cout << "Mulfun for T1 = [ " << typeid(T1).name() << " ]\t T2 = [ " << typeid(T2).name() << " ]\n";
	return x * y;
}
```
