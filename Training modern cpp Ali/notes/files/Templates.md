## Templates
- C++ templates are a powerful feature that allows programmers to write generic code that can work with any data type. Templates provide a way to define functions, classes, or data structures that are parameterized by one or more types. This enables code reusability and flexibility in designing algorithms and data structures.
- rtti : runtime type identification.


1. **Function Templates :** Function templates allow you to define a function without specifying the data types of its parameters. Instead, you use placeholders (typically typename or class) to represent the types. When you call the function with specific types, the compiler generates the appropriate version of the function for those types.
```cpp
template<typename T>
T add(T a, T b) {
    return a + b;
}

int result1 = add<int>(5, 3);
double result2 = add<double>(3.5, 2.7);
```
2. **Class Templates :** Class templates allow you to define a class in which one or more of its data members or member functions are of a generic type. This allows you to create classes that can work with different types of data.
```cpp
template<typename T>
class Container {
private:
    T item;
public:
    Container(T val) : item(val) {}
    T getItem() const { return item; }
};

Container<int> intContainer(10);
Container<double> doubleContainer(3.14);
```
3. **Template Specialization :** Template specialization allows you to provide custom implementations for specific types while still using a generic template for other types. This is useful when you need different behavior for certain types.
```cpp
template<typename T>
void print(T value) {
    cout << value << endl;
}

template<>
void print<string>(string value) {
    cout << "String: " << value << endl;
}

print(10);       // Calls the generic version of print()
print("hello");  // Calls the specialized version for string
```
## Variadic Template
- Templates that accept a variable number of template arguments, often facilitated by parameter packs. They provide a powerful mechanism for writing generic code that can handle arbitrary numbers and types of arguments.
```cpp
	void printMe()
	{
		cout<< "Print Me" << '\n';
	}
	
	template<typename T>
	void printMe(T par) //function specialization
	{
		cout << par << " :  end\n";
	}
	template<typename T1,typename T2>
	void printMe(T1 par,T2 par2) 
	{
		cout << par <<" -> "<<par2 << " :  end\n";
	}

	template<typename T1, typename... T> //Template packing
	void printMe(T1 p, T... par)//parameter pack
	{
		cout << p << '\t';
		printMe(par...);//unpacking
	}

	int main()
	{
		printMe(10, 20, 30, 50);
		printMe(100, 'c', 3.141, 2.12f);
		printMe(100);
		printMe();
		return 0;
	}
```


## Templates Example : 
```cpp
template<typename T1, typename T2>
T2 SubFun(T1 x, T1 y)
{
	//rtti -> runtime type identification
	cout << "Subfun for T1 = [ " << typeid(T1).name() << " ]\t T2 = [ " << typeid(T2).name() << " ]\n";
	return x + y;
}
int main()
{
	double d = SubFun<int, double>(10, 20);
	// auto d1 = SubFun(1.0, 2.0); //will not work
	return 0;
}
```
- Below function uses trailing return type syntax to explicitly specify the return type as the type of the expression `x * y`.
```cpp
template<typename T1, typename T2>
auto MulFun(T1 x, T2 y)->decltype(x* y)  //trailing deduce : c++11 onwards
{
	cout << "Mulfun for T1 = [ " << typeid(T1).name() << " ]\t T2 = [ " << typeid(T2).name() << " ]\n";
	return x * y;
}
int main()
{
	auto m1 = MulFun(2.3, 4);  //d
	cout << "m1= [ " << typeid(m1).name() << " ]\n";
	return 0;
}
```
- Below function also uses trailing return type syntax to specify the return type. However, in this case, it explicitly deduces the return type as the same as the return type of another function call `(MulFun(x, y))`. 
```cpp
template<typename T1, typename T2>
auto MulFunNew(T1 x, T2 y)->decltype(MulFun(x, y))
{
	cout << "MulfunNew for T1 = [ " << typeid(T1).name() << " ]\t T2 = [ " << typeid(T2).name() << " ]\n";
	return x * y;
}
int main()
{
	auto m2 = MulFunNew(1, 2.3); //d
	cout << "m2= [ " << typeid(m2).name() << " ]\n";
	return 0;
}
```
- Below function uses the `auto` keyword to automatically deduce the return type based on the type of the expression x * y.
```cpp
template<typename T1, typename T2>
auto MulFunNew14(T1 x, T2 y) //auto return type deduce : c++14
{
	cout << "MulfunNew14 for T1 = [ " << typeid(T1).name() << " ]\t T2 = [ " << typeid(T2).name() << " ]\n";
	return x * y;
}
int main()
{
	auto m2 = MulFunNew14(1, 2.3); //d
	cout << "m2= [ " << typeid(m2).name() << " ]\n";
	return 0;
}
```
- Below function also uses the `auto` keyword, but it explicitly specifies the return type using the **trailing return type syntax** `(-> double)`. This means that the return type is explicitly stated as *double*, regardless of the type of the expression in return type.
```cpp
template<typename T1, typename T2>
auto MulFunNew14_1(T1 x, T2 y)->double //auto return type deduce : c++14
{
	int par = 10;
	cout << "MulfunNew14 for T1 = [ " << typeid(T1).name() << " ]\t T2 = [ " << typeid(T2).name() << " ]\n";
	if (10 == par)
	{
		return 3.14;
	}
	return 2;
}
int main()
{
	auto m2 = MulFunNew14_1(1, 2.3); //d
	cout << "m2= [ " << typeid(m2).name() << " ]\n"; //d
	cout <<m2 <<'\n'; //2
	return 0;
}
```
```cpp
struct Shubam
{
	char c;
	int x;
	double y;
};

template<int index = 0>
auto GetStruct(Shubam& shubam)
{
	if constexpr (0 == index)
		return shubam.c;
	else if constexpr (1 == index)
		return shubam.x;
	else
		return shubam.y;
}
int main()
{
	Shubam s{ 'c',123 ,3.141 };
	cout << GetStruct(s) << '\n'; //c
	cout << GetStruct<1>(s) << '\n'; //123 
	cout << GetStruct<2>(s) << '\n'; //3.141
	return 0;
}
```
